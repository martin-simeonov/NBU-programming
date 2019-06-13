package bg.nbu.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;

import bg.nbu.entity.Emergency;
import bg.nbu.entity.User;
import bg.nbu.service.EmergencyService;
import bg.nbu.service.UserService;

@Controller
@Secured(User.RoleAdmin)
public class AdminController {

	@Autowired
	private UserService userService;

	@Autowired
	private EmergencyService emergencyService;

	@RequestMapping("/admin")
	public String getEmployees(Model model) {
		List<User> employees = userService.getEmployees();
		model.addAttribute("employees", employees);

		return "listEmployees";
	}

	@RequestMapping(value = "/admin/deleteEmployee/{id}")
	public String deleteProgram(@PathVariable("id") Long id) {
		userService.delete(id);
		
		return "redirect:/admin";
	}

	@RequestMapping("/admin/statistics")
	public String getStatistics(Model model) {
		List<Emergency> emergencies = emergencyService.getAllEmergencies();
		model.addAttribute("emergencies", emergencies);

		return "statistics";
	}

}
