package bg.nbu.controller;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

import javax.validation.Valid;

import bg.nbu.dto.RepairDto;
import bg.nbu.dto.ServiceTypeDto;
import bg.nbu.entity.*;
import bg.nbu.service.CarService;
import bg.nbu.service.RepairService;
import bg.nbu.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.*;

@Secured(User.RoleUser)
@Controller
public class UserController {

    @Autowired
    private CarService carService;

    @Autowired
    private UserService userService;

    @Autowired
    private RepairService repairService;

    @RequestMapping("/user")
    public String getCars(Model model) {
        List<Car> cars = carService.getCarsByUser(userService.currentUserId());
        model.addAttribute("cars", cars);

        return "listCars";
    }

    @RequestMapping(value = {"/addCar"}, method = RequestMethod.GET)
    public String addCar(Model model) {
        model.addAttribute("car", new Car());
        return "addCar";
    }

    @RequestMapping(value = {"/addCar"}, method = RequestMethod.POST)
    public String addCar(@ModelAttribute("car") @Valid Car car, BindingResult result) {
        if (result.hasErrors()) {
            return "addCar";
        }

        carService.addCar(car);

        return "redirect:/user";
    }

    @RequestMapping(value = {"/car/schedule_repair/{id}"}, method = RequestMethod.POST)
    public String chooseService(@ModelAttribute("skills") Skills skill, @PathVariable("id") Long id, Model model) {
        Car car = carService.getCar(id);
        List<User> shops = userService.findAvailableShops(skill, car);
        model.addAttribute("shops", shops);
        RepairDto repairDto = new RepairDto();
        repairDto.setCarId(id);
        repairDto.setDateTime(new Date().toString());
        repairDto.setJobType(skill.toString());
        model.addAttribute("repair", repairDto);

        return "listShops";
    }

    @RequestMapping(value = {"/car/schedule_repair/{id}"}, method = RequestMethod.GET)
    public String scheduleRepair(@PathVariable("id") Long id, Model model) {
        model.addAttribute("id", id);
        model.addAttribute("serviceType", new ServiceTypeDto());
        model.addAttribute("skills", Skills.values());

        return "chooseService";
    }

    @RequestMapping(value = {"/car/save_repair"}, method = RequestMethod.POST)
    public String saveRepair(@ModelAttribute("repair") RepairDto repairDto) {
        Repair repair = new Repair();
        Date date = new Date();
        try {
            date =new SimpleDateFormat("yyyy-MM-dd'T'HH:mm").parse(repairDto.getDateTime());
        } catch (ParseException e) {
            e.printStackTrace();
        }
        repair.setDateTime(date);
        repair.setShop(userService.findById(repairDto.getShopId()));
        repair.setCar(carService.getCar(repairDto.getCarId()));
        repair.setPending(true);
        repair.setJobType(repairDto.getJobType());

        repairService.addRepair(repair);

        return "redirect:/user";
    }

    @RequestMapping(value = {"/car/repairs/{id}"}, method = RequestMethod.GET)
    public String getCarRepairs(@PathVariable("id") Long id, Model model) {
        model.addAttribute("repairs", repairService.getRepairsByCar(id));

        return "listRepairs";
    }

    @RequestMapping("/car/delete/{id}")
    public String deleteCar(@PathVariable("id") Long id) {
        carService.deleteCar(id);

        return "redirect:/user";
    }

}
