package bg.nbu.carservice.controller;

import bg.nbu.carservice.entity.Car;
import bg.nbu.carservice.service.CarService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class CarController {
    @Autowired
    private CarService carService;

    @RequestMapping(method = RequestMethod.GET, value = "/car/{id}")
    public Car getCar(@PathVariable("id") Long id) {
        return carService.getCar(id);
    }

    @RequestMapping(method = RequestMethod.GET, value = "/car")
    public List<Car> getAllCars() {
        return carService.getAllCars();
    }

    @RequestMapping("/car/user/{userId}")
    public List<Car> getCarsByUser(@PathVariable("userId") Long userId) {
        return carService.getCarsByUser(userId);
    }

    @RequestMapping(method = RequestMethod.POST, value = "/car")
    public void addCar(@RequestBody Car car) {
        carService.addCar(car);
    }

    @RequestMapping(method = RequestMethod.PUT, value = "/car")
    public void updateCar(@RequestBody Car car) {
        carService.updateCar(car);
    }

    @RequestMapping(method = RequestMethod.DELETE, value = "/car/{id}")
    public void deleteCar(@PathVariable("id") Long id) {
        carService.deleteCar(id);
    }
}
