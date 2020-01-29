package bg.nbu.service;

import bg.nbu.entity.Repair;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.List;

@Service
public class RepairService {
    @Autowired
    private RestTemplate restTemplate;

    public void addRepair(Repair repair) {
        HttpEntity<Repair> request = new HttpEntity<>(repair);
        restTemplate.postForObject("http://localhost:8083/repair", request, Repair.class);
    }

    public void updateRepair(Repair repair) {
        HttpEntity<Repair> request = new HttpEntity<>(repair);
        restTemplate.put("http://localhost:8083/repair", request, Repair.class);
    }

    public Repair getRepair(Long id) {
        Repair repair = restTemplate.getForObject("http://localhost:8083/repair/" + id, Repair.class);
        return repair;
    }

    public Repair[] getAllRepairs() {
        Repair[] repairs = restTemplate.getForObject("http://localhost:8083/repair", Repair[].class);
        return repairs;
    }

    public List<Repair> getRepairsByCar(Long id) {
        List<Repair> repairs = restTemplate.getForObject("http://localhost:8083/repair/car/" + id, List.class);
        return repairs;
    }

    public Repair[] getRepairsByShop(Long id) {
        Repair[] repairs = restTemplate.getForObject("http://localhost:8083/repair/shop/" + id, Repair[].class);
        return repairs;
    }
}
