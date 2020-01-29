package bg.nbu.carservice.service;

import bg.nbu.carservice.entity.Car;
import bg.nbu.carservice.repository.CarRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class CarService {

    @Autowired
    private CarRepository carRepository;

    public Car getCar(Long id) {
        return carRepository.findById(id)
                .orElseThrow(() -> new IllegalArgumentException("Invalid car id:" + id));
    }

    public List<Car> getAllCars() {
        List<Car> cars = new ArrayList<>();
        carRepository.findAll().forEach(cars::add);
        return cars;
    }

    public List<Car> getCarsByUser(Long userId) {
        return getAllCars().stream().filter(c -> c.getOwnerId().equals(userId)).collect(Collectors.toList());
    }

    public void addCar(Car car) {
        carRepository.save(car);
    }

    public void updateCar(Car car) {
        carRepository.save(car);
    }

    public void deleteCar(Long id) {
        Car car = carRepository.findById(id)
                .orElseThrow(() -> new IllegalArgumentException("Invalid car id:" + id));
        carRepository.delete(car);
    }
}
