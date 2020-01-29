package bg.nbu.controller;

import bg.nbu.dto.ShopRegistrationDto;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
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

	@ModelAttribute("shop")
	public ShopRegistrationDto shopRegistrationDto() {
		return new ShopRegistrationDto();
	}

    @RequestMapping(value = {"/registration"}, method = RequestMethod.GET)
    public String showRegistrationForm(Model model) {
        return "registration";
    }

	@Secured(User.RoleAdmin)
    @RequestMapping(value = {"/registrationShop"}, method = RequestMethod.GET)
    public String showRegistrationFormForShop(Model model) {
        return "registrationShop";
    }

    @RequestMapping(value = {"/registration"}, method = RequestMethod.POST)
    public String registerUserAccount(@ModelAttribute("user") @Valid RegistrationDto userDto, BindingResult result,
                                      Authentication authentication) {

        User existing = userService.findByEmail(userDto.getEmail());
        if (existing != null) {
            result.rejectValue("email", null, "There is already an account registered with that email");
        }

        boolean isShop = false;
        if (authentication != null) {
            UserDetails userDetails = (UserDetails) authentication.getPrincipal();
            for (GrantedAuthority grantedAuthority : userDetails.getAuthorities()) {
                if (grantedAuthority.getAuthority().equals(User.RoleShop)) {
                    isShop = true;
                    break;
                }
            }
        }

        if (result.hasErrors()) {
            return "registration";
        }

        if (isShop) {
            userService.saveWorker(userDto);
            return "redirect:/shop";
        } else {
            userService.save(userDto);
            return "redirect:/registration?success";
        }

    }

	@Secured(User.RoleAdmin)
    @RequestMapping(value = {"/registrationShop"}, method = RequestMethod.POST)
    public String registerShop(@ModelAttribute("shop") @Valid ShopRegistrationDto userDto, BindingResult result,
                               Authentication authentication) {

        User existing = userService.findByEmail(userDto.getEmail());
        if (existing != null) {
            result.rejectValue("email", null, "There is already an account registered with that email");
        }

        if (result.hasErrors()) {
            return "registrationShop";
        }

        userService.saveShop(userDto);

        return "redirect:/admin";
    }

}
