package bg.nbu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.GrantedAuthority;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import bg.nbu.dto.RegistrationDto;
import bg.nbu.entity.User;
import bg.nbu.service.UserService;

import javax.validation.Valid;

@Controller
public class RegistrationController {

	@Autowired
	private UserService userService;

	@ModelAttribute("user")
	public RegistrationDto userRegistrationDto() {
		return new RegistrationDto();
	}

	@RequestMapping(value = { "/registration" }, method = RequestMethod.GET)
	public String showRegistrationForm(Model model) {
		return "registration";
	}

	@RequestMapping(value = { "/registration" }, method = RequestMethod.POST)
	public String registerUserAccount(@ModelAttribute("user") @Valid RegistrationDto userDto, BindingResult result,
			Authentication authentication) {

		User existing = userService.findByEmail(userDto.getEmail());
		if (existing != null) {
			result.rejectValue("email", null, "There is already an account registered with that email");
		}

		boolean isAdmin = false;
		if (authentication != null) {
			UserDetails userDetails = (UserDetails) authentication.getPrincipal();
			for (GrantedAuthority grantedAuthority : userDetails.getAuthorities()) {
				if (grantedAuthority.getAuthority().equals(User.RoleAdmin)) {
					isAdmin = true;
					break;
				}
			}
		}

		if (result.hasErrors()) {
			return "registration";
		}

		if (isAdmin) {
			userService.saveEmployee(userDto);
			return "redirect:/admin";
		} else {
			userService.save(userDto);
			return "redirect:/registration?success";
		}

	}

}
