package bg.nbu.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.authority.SimpleGrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;

import bg.nbu.dto.RegistrationDto;
import bg.nbu.entity.Role;
import bg.nbu.entity.User;
import bg.nbu.repository.UserRepository;

import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.security.core.userdetails.UserDetailsService;

@Service
public class UserService implements UserDetailsService {

	@Autowired
	private UserRepository userRepository;

	@Autowired
	private BCryptPasswordEncoder passwordEncoder;

	public User findByEmail(String email) {
		return userRepository.findByEmail(email);
	}

	public void save(RegistrationDto registration) {
		saveUser(registration, Arrays.asList(new Role(User.RoleUser)));
	}

	public void saveEmployee(RegistrationDto registration) {
		saveUser(registration, Arrays.asList(new Role(User.RoleEmployee)));
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

	public List<User> getEmployees() {
		return userRepository.findAll().stream()
				.filter(u -> u.getRoles().stream().filter(r -> r.getName().equals(User.RoleEmployee)).count() > 0)
				.collect(Collectors.toList());
	}

	public User getEmployee(Long id) {
		return userRepository.findById(id).get();
	}

	public void delete(Long id) {
		userRepository.deleteById(id);
	}
}
