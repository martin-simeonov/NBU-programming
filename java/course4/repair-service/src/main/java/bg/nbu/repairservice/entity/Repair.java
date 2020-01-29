package bg.nbu.repairservice.entity;

import javax.persistence.*;
import java.util.Date;

@Entity
public class Repair {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;
    @OneToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "car_id")
    private Car car;
    @OneToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "shop_id")
    private User shop;
    @OneToOne(fetch = FetchType.EAGER)
    @JoinColumn(name = "worker_id")
    private User worker;
    private Boolean pending;
    private Date dateTime;
    private Double price;
    private String description;
    private String jobType;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Boolean getPending() {
        return pending;
    }

    public void setPending(Boolean pending) {
        this.pending = pending;
    }

    public Date getDateTime() {
        return dateTime;
    }

    public void setDateTime(Date dateTime) {
        this.dateTime = dateTime;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public String getJobType() {
        return jobType;
    }

    public void setJobType(String jobType) {
        this.jobType = jobType;
    }

    public Car getCar() {
        return car;
    }

    public void setCar(Car car) {
        this.car = car;
    }

    public User getWorker() {
        return worker;
    }

    public void setWorker(User worker) {
        this.worker = worker;
    }

    public User getShop() {
        return shop;
    }

    public void setShop(User shop) {
        this.shop = shop;
    }
}
