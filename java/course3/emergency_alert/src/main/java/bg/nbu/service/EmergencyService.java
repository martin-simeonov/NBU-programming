package bg.nbu.service;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.User;
import org.springframework.stereotype.Service;

import bg.nbu.entity.Emergency;
import bg.nbu.repository.EmergencyRepository;
import bg.nbu.repository.UserRepository;

@Service
public class EmergencyService {

	@Autowired
	private EmergencyRepository emergencyRepository;

	@Autowired
	private UserRepository userRepository;

	public List<Emergency> getAllEmergencies() {
		List<Emergency> emergencies = new ArrayList<>();
		emergencyRepository.findAll().forEach(e -> emergencies.add(e));
		return emergencies;
	}

	public List<Emergency> getUnresolvedEmergencies() {
		return getAllEmergencies().stream().filter(e -> e.getResolver() == null).collect(Collectors.toList());
	}

	public List<Emergency> getEmergenciesByUser() {
		User currentUser = (User) SecurityContextHolder.getContext().getAuthentication().getPrincipal();
		return userRepository.findByEmail(currentUser.getUsername()).getSentEmergencies();
	}

	public void addEmergency(Emergency emergency) {
		User currentUser = (User) SecurityContextHolder.getContext().getAuthentication().getPrincipal();
		emergency.setSender(userRepository.findByEmail(currentUser.getUsername()));
		emergency.setIncomeTime(new Date());
		emergencyRepository.save(emergency);
	}

	public void resolveEmergency(Long id) {
		Emergency emergency = emergencyRepository.findById(id).get();
		emergency.setResolveTime(new Date());

		User currentUser = (User) SecurityContextHolder.getContext().getAuthentication().getPrincipal();
		emergency.setResolver(userRepository.findByEmail(currentUser.getUsername()));

		emergencyRepository.save(emergency);
	}

}
