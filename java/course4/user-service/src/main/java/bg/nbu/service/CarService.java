package bg.nbu.service;

import bg.nbu.entity.Car;
import bg.nbu.repository.UserRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpEntity;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.User;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.List;

@Service
public class CarService {

    @Autowired
    private UserRepository userRepository;

    @Autowired
    private RestTemplate restTemplate;

    public Car getCar(Long id) {
        Car car = restTemplate.getForObject("http://localhost:8081/car/" + id, Car.class);
        return car;
    }

    public List<Car> getCarsByUser(Long id) {
        List<Car> cars = restTemplate.getForObject("http://localhost:8081/car/user/" + id, List.class);
        return cars;
    }

    public void addCar(Car car) {
        User currentUser = (User) SecurityContextHolder.getContext().getAuthentication().getPrincipal();
        car.setOwnerId(userRepository.findByEmail(currentUser.getUsername()).getId());

        HttpEntity<Car> request = new HttpEntity<>(car);
        restTemplate.postForObject("http://localhost:8081/car", request, Car.class);
    }

    public void deleteCar(Long id) {
        restTemplate.delete("http://localhost:8081/car/" + id);
    }
}
