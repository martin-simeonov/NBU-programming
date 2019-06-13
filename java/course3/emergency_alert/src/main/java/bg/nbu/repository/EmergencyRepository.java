package bg.nbu.repository;

import java.util.List;

import org.springframework.data.repository.CrudRepository;

import bg.nbu.entity.Emergency;
import bg.nbu.entity.User;

public interface EmergencyRepository extends CrudRepository<Emergency, Long> {

	List<Emergency> findAllBySender(User user);
	
}
