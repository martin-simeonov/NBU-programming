package bg.nbu.repairservice.repository;

import bg.nbu.repairservice.entity.Repair;
import org.springframework.data.repository.CrudRepository;

public interface RepairRepository extends CrudRepository<Repair, Long> {
}
