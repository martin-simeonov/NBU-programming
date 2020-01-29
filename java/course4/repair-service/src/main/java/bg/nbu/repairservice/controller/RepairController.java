package bg.nbu.repairservice.controller;

import bg.nbu.repairservice.entity.Repair;
import bg.nbu.repairservice.service.RepairService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class RepairController {

    @Autowired
    private RepairService repairService;

    @RequestMapping(method = RequestMethod.POST, value = "/repair")
    public void addRepair(@RequestBody Repair repair) {
        repairService.addRepair(repair);
    }

    @RequestMapping(method = RequestMethod.GET, value = "/repair")
    public List<Repair> getAllRepairs() {
        return repairService.getAllRepairs();
    }

    @RequestMapping(method = RequestMethod.PUT, value = "/repair")
    public void updateRepair(@RequestBody Repair repair) {
        repairService.updateRepair(repair);
    }

    @RequestMapping("/repair/{id}")
    public Repair getRepair(@PathVariable("id") Long id) {
        return repairService.getRepair(id);
    }

    @RequestMapping("/repair/car/{carId}")
    public List<Repair> getRepairsByUser(@PathVariable("carId") Long carId) {
        return repairService.getRepairsByCar(carId);
    }

    @RequestMapping("/repair/shop/{shopId}")
    public List<Repair> getRepairsByShop(@PathVariable("shopId") Long shopId) {
        return repairService.getRepairsByShop(shopId);
    }
}
