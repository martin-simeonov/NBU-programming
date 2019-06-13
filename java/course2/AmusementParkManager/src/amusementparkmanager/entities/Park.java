package amusementparkmanager.entities;
// Generated Jan 16, 2019 3:49:40 PM by Hibernate Tools 4.3.1

import amusementparkmanager.services.ManagerService;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Park generated by hbm2java
 */
public class Park implements java.io.Serializable {

    private Set<Installation> installations;
    private List<Child> visitors;
    private Integer parkId;
    private Manager manager;
    private String name;
    private Double saleThreshold;
    private Integer salaryIncrease;
    private Double ticketPrice;

    public Park() {
        this.installations = new HashSet<>();
        this.visitors = new ArrayList<>();
    }

    public Park(Manager manager, String name, Double saleThreshold,
            Integer salaryIncrease, Double ticketPrice) {
        this.installations = new HashSet<>();
        this.manager = manager;
        this.name = name;
        this.saleThreshold = saleThreshold;
        this.salaryIncrease = salaryIncrease;
        this.ticketPrice = ticketPrice;
    }

    public Park(Manager manager, String name, Double saleThreshold,
            Integer salaryIncrease, Double ticketPrice, HashSet<Installation> installations) {
        this(manager, name, saleThreshold, salaryIncrease, ticketPrice);
        this.installations = installations;
    }

    public Integer getParkId() {
        return this.parkId;
    }

    public void setParkId(Integer parkId) {
        this.parkId = parkId;
    }

    public Manager getManager() {
        return this.manager;
    }

    public void setManager(Manager manager) {
        this.manager = manager;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Double getSaleThreshold() {
        return this.saleThreshold;
    }

    public void setSaleThreshold(Double saleThreshold) {
        this.saleThreshold = saleThreshold;
    }

    public Integer getSalaryIncrease() {
        return this.salaryIncrease;
    }

    public void setSalaryIncrease(Integer salaryIncrease) {
        this.salaryIncrease = salaryIncrease;
    }

    public Set<Installation> getInstallations() {
        return installations;
    }

    public void setInstallations(Set<Installation> installations) {
        this.installations = installations;
    }

    public List<Child> getVisitors() {
        return visitors;
    }

    public void setVisitors(List<Child> visitors) {
        this.visitors = visitors;
    }

    public boolean makeSale(Child visitor) {
        if (!getAccessibleInstallations(visitor).isEmpty()) {
            visitors.add(visitor);
            
            if (getIncome() > saleThreshold) {
                manager.increaseSalary(salaryIncrease);
                
                // Update in database
                ManagerService.update(manager);
            }
            return true;
        }
        return false;
    }
    
    public List<Installation> getAccessibleInstallations(Child child) {
        return installations.stream().
                filter(i -> i.getMinAge() <= child.getAge()).collect(Collectors.toList());
    }
    
    public Double getTicketPrice() {
        return ticketPrice;
    }

    public void setTicketPrice(Double ticketPrice) {
        this.ticketPrice = ticketPrice;
    }
    
    public Double getIncome() {
        return ticketPrice * visitors.size();
    }

    @Override
    public String toString() {
        return name;
    }

}