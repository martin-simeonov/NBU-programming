package bg.nbu.service;

import bg.nbu.dto.ShopRegistrationDto;
import bg.nbu.entity.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import bg.nbu.dto.RegistrationDto;
import bg.nbu.repository.UserRepository;

import java.util.*;
import java.util.stream.Collectors;

import org.springframework.security.core.userdetails.UserDetailsService;

@Service
public class UserService implements UserDetailsService {

    @Autowired
    private UserRepository userRepository;

    @Autowired
    private BCryptPasswordEncoder passwordEncoder;

    public Long currentUserId() {
        org.springframework.security.core.userdetails.User user = (org.springframework.security.core.userdetails.User)
                SecurityContextHolder.getContext().getAuthentication().getPrincipal();
        return userRepository.findByEmail(user.getUsername()).getId();
    }

    public User findByEmail(String email) {
        return userRepository.findByEmail(email);
    }

    public User findById(Long id) {
        return userRepository.findById(id).get();
    }

    public void save(RegistrationDto registration) {
        saveUser(registration, Arrays.asList(new Role(User.RoleUser)));
    }

    public void saveWorker(RegistrationDto registration) {
        User user = new User();
        user.setFirstName(registration.getFirstName());
        user.setLastName(registration.getLastName());
        user.setEmail(registration.getEmail());
        user.setPassword(passwordEncoder.encode(registration.getPassword()));
        user.setRoles(Arrays.asList(new Role(User.RoleWorker)));
        // Current user is shop
        user.setShop(currentUserId());
        userRepository.save(user);
    }

    public void saveShop(ShopRegistrationDto registration) {
        RegistrationDto registrationDto = new RegistrationDto();
        registrationDto.setFirstName(registration.getFirstName());
        registrationDto.setLastName("shop");
        registrationDto.setEmail(registration.getEmail());
        registrationDto.setPassword(registration.getPassword());
        saveUser(registrationDto, Arrays.asList(new Role(User.RoleShop)));
    }

    private void saveUser(RegistrationDto registration, List<Role> roles) {
        User user = new User();
        user.setFirstName(registration.getFirstName());
        user.setLastName(registration.getLastName());
        user.setEmail(registration.getEmail());
        user.setPassword(passwordEncoder.encode(registration.getPassword()));
        user.setRoles(roles);
        userRepository.save(user);
    }

    public void createAdmin() {
        if (userRepository.findByEmail("admin") == null) {
            User user = new User();
            user.setEmail("admin");
            user.setPassword(passwordEncoder.encode("admin"));
            user.setRoles(Arrays.asList(new Role(User.RoleAdmin)));
            userRepository.save(user);
        }
    }

    public void saveUser(User user) {
        userRepository.save(user);
    }

    public UserDetails loadUserByUsername(String email) throws UsernameNotFoundException {
        User user = userRepository.findByEmail(email);
        if (user == null) {
            throw new UsernameNotFoundException("Invalid username or password.");
        }
        return new org.springframework.security.core.userdetails.User(user.getEmail(), user.getPassword(),
                mapRolesToAuthorities(user.getRoles()));
    }

    private Collection<? extends GrantedAuthority> mapRolesToAuthorities(Collection<Role> roles) {
        return roles.stream().map(role -> new SimpleGrantedAuthority(role.getName())).collect(Collectors.toList());
    }

    public List<User> getShops() {
        return userRepository.findAll().stream()
                .filter(u -> u.getRoles().stream().filter(r -> r.getName().equals(User.RoleShop)).count() > 0)
                .collect(Collectors.toList());
    }

    public List<User> getWorkers() {
        Long currentShop = currentUserId();
        return userRepository.findAll().stream()
                .filter(u -> u.getRoles().stream().filter(r -> r.getName().equals(User.RoleWorker)).count() > 0 && u.getShopId().equals(currentShop))
                .collect(Collectors.toList());
    }

    public User getEmployee(Long id) {
        return userRepository.findById(id).get();
    }

    public void delete(Long id) {
        userRepository.deleteById(id);
    }

    public List<User> findAvailableShops(Skills skill, Car car) {
        // List of workers that can perform this task
        List<User> workers = userRepository.findAll().stream().filter(s -> s.getSkills() != null && s.getSkills().stream().filter(sk -> sk.equals(skill)).count() > 0).collect(Collectors.toList());
        // Get their shops
        Set<User> shops = new HashSet<>();
        for (User u : workers) {
            User shop = userRepository.findById(u.getShopId()).get();
            shops.add(shop);
        }
        return new ArrayList<>(shops);
    }
}
