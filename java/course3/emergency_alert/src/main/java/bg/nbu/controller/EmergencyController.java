package bg.nbu.controller;

import java.security.Principal;
import java.util.List;

import javax.validation.Valid;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import bg.nbu.entity.Emergency;
import bg.nbu.entity.User;
import bg.nbu.service.EmergencyService;

@Controller
public class EmergencyController {

	@Autowired
	private EmergencyService emergencyService;

	@Secured(User.RoleEmployee)
	@RequestMapping("/emergencyEmployee")
	public String getEmergenciesEmployee(Model model) {
		List<Emergency> emergencies = emergencyService.getUnresolvedEmergencies();
		model.addAttribute("emergencies", emergencies);

		return "emergencyEmployee";
	}

	@Secured(User.RoleUser)
	@RequestMapping("/emergency")
	public String getEmergencies(Model model, Principal principal) {
		List<Emergency> emergencies = emergencyService.getEmergenciesByUser();
		model.addAttribute("emergencies", emergencies);

		return "emergency";
	}

	@Secured(User.RoleUser)
	@RequestMapping(value = { "/addEmergency" }, method = RequestMethod.GET)
	public String addEmergency(Model model) {
		model.addAttribute("emergency", new Emergency());
		return "addEmergency";
	}

	@Secured(User.RoleUser)
	@RequestMapping(value = { "/addEmergency" }, method = RequestMethod.POST)
	public String addEmergency(@ModelAttribute("emergency") @Valid Emergency emergency, BindingResult result) {
		if (result.hasErrors()) {
			return "addEmergency";
		}

		emergencyService.addEmergency(emergency);

		return "redirect:/emergency";
	}
	
	@Secured(User.RoleEmployee)
	@RequestMapping(value = "/resolveEmergency/{id}")
	public String resolveEmergency(@PathVariable("id") Long id) {
		emergencyService.resolveEmergency(id);
		
		return "redirect:/emergencyEmployee";
	}


}
