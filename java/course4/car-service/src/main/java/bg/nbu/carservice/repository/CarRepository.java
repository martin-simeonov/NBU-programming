package bg.nbu.carservice.repository;

import bg.nbu.carservice.entity.Car;
import org.springframework.data.repository.CrudRepository;

public interface CarRepository extends CrudRepository<Car, Long> {
}
