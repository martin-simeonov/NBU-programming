package bg.nbu.controller;

import bg.nbu.entity.Skill;
import bg.nbu.entity.Skills;
import bg.nbu.entity.User;
import bg.nbu.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import java.util.List;

@Controller
@Secured(User.RoleShop)
public class ShopController {

    @Autowired
    private UserService userService;

    @RequestMapping("/shop")
    public String getWorkers(Model model) {
        List<User> workers = userService.getWorkers();
        model.addAttribute("workers", workers);

        return "listWorkers";
    }

    @RequestMapping(value = {"/shop/skill/{id}"}, method = RequestMethod.GET)
    public String getWorkerSkills(Model model, @PathVariable("id") Long id) {
        User worker = userService.findById(id);
        model.addAttribute("worker", worker);
        model.addAttribute("skills", Skills.values());

        return "addSkill";
    }

    @RequestMapping(value = {"/shop/skill/{id}"}, method = RequestMethod.POST)
    public String saveWorkerSkills(@ModelAttribute("skills") Skills skill, @PathVariable("id") Long id) {
        User worker = userService.findById(id);
        worker.getSkills().add(new Skill(skill.name()));
        userService.saveUser(worker);

        return "redirect:/shop";
    }

	@RequestMapping(value = "/shop/delete/{id}")
	public String deleteWorker(@PathVariable("id") Long id) {
		userService.delete(id);
		
		return "redirect:/shop";
	}

}
