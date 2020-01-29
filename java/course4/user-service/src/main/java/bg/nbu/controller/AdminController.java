package bg.nbu.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import bg.nbu.entity.User;
import bg.nbu.service.UserService;

@Controller
@Secured(User.RoleAdmin)
public class AdminController {

	@Autowired
	private UserService userService;

	@RequestMapping("/admin")
	public String getEmployees(Model model) {
		List<User> shops = userService.getShops();
		model.addAttribute("shops", shops);

		return "listShops";
	}
}
