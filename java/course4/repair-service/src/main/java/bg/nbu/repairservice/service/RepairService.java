package bg.nbu.repairservice.service;

import bg.nbu.repairservice.entity.Repair;
import bg.nbu.repairservice.repository.RepairRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class RepairService {

    @Autowired
    private RepairRepository repairRepository;

    public Repair getRepair(Long id) {
        return repairRepository.findById(id)
                .orElseThrow(() -> new IllegalArgumentException("Invalid repair id:" + id));
    }

    public List<Repair> getAllRepairs() {
        List<Repair> cars = new ArrayList<>();
        repairRepository.findAll().forEach(cars::add);
        return cars;
    }

    public List<Repair> getRepairsByCar(Long id) {
        return getAllRepairs().stream().filter(c -> c.getCar().getId().equals(id)).collect(Collectors.toList());
    }

    public List<Repair> getRepairsByShop(Long id) {
        return getAllRepairs().stream().filter(c -> c.getShop().getId().equals(id)).collect(Collectors.toList());
    }

    public void addRepair(Repair repair) {
        repairRepository.save(repair);
    }

    public void updateRepair(Repair repair) {
        repairRepository.save(repair);
    }

    public void deleteRepair(Long id) {
        Repair repair = repairRepository.findById(id)
                .orElseThrow(() -> new IllegalArgumentException("Invalid repair id:" + id));
        repairRepository.delete(repair);
    }
}

