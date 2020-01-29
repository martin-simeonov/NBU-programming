package bg.nbu.controller;

import bg.nbu.dto.StatisticsDto;
import bg.nbu.entity.*;
import bg.nbu.service.RepairService;
import bg.nbu.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.annotation.Secured;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import javax.validation.Valid;

@Controller
@Secured(User.RoleWorker)
public class WorkerController {

    @Autowired
    RepairService repairService;

    @Autowired
    UserService userService;

    @RequestMapping("/worker")
    public String getRepairs(Model model) {
        Long shopId = userService.findById(userService.currentUserId()).getShopId();
        Repair[] repairs = repairService.getRepairsByShop(shopId);
        model.addAttribute("repairs", repairs);

        return "listRepairs";
    }

    @RequestMapping(value = {"/worker/repair/{repairId}"}, method = RequestMethod.GET)
    public String doRepair(@PathVariable("repairId") Long repairId, Model model) {
        Repair repair = new Repair();
        repair.setId(repairId);
        model.addAttribute("repair", repair);

        return "doRepair";
    }

    @RequestMapping(value = {"/worker/repair"}, method = RequestMethod.POST)
    public String doRepair(@ModelAttribute("repair") @Valid Repair saveRepair) {
        Repair repair = repairService.getRepair(saveRepair.getId());
        repair.setWorker(userService.findById(userService.currentUserId()));
        repair.setPending(false);
        repair.setPrice(saveRepair.getPrice());
        repair.setDescription(saveRepair.getDescription());
        repairService.updateRepair(repair);

        return "redirect:/worker";
    }

    @RequestMapping("/worker/statistics")
    public String getStatistics(Model model) {
        StatisticsDto statistics = new StatisticsDto();
        User user = userService.findById(userService.currentUserId());
        Repair[] repairs = repairService.getRepairsByShop(user.getShopId());

        for (Repair r : repairs) {
            statistics.getCountBySkill().put(r.getJobType(), statistics.getCountBySkill().getOrDefault(r.getJobType(), 0L) + 1L);
            statistics.getCountByMake().put(r.getCar().getMake(), statistics.getCountByMake().getOrDefault(r.getCar().getMake(), 0L) + 1L);
            statistics.getCountByYear().put(r.getCar().getYear(), statistics.getCountByYear().getOrDefault(r.getCar().getYear(), 0L) + 1L);
        }
        model.addAttribute("statistics", statistics);

        return "statistics";
    }

}
