package bg.nbu.entity;

import java.util.Date;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.ManyToOne;
import javax.validation.constraints.NotBlank;

@Entity
public class Emergency {
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	private Long id;

	@NotBlank(message = "Provide address")
	private String address;
	@NotBlank(message = "Provide description")
	private String description;
	private Date incomeTime;
	private Date resolveTime;

	@ManyToOne
	private User sender;
	@ManyToOne
	private User resolver;

	public Emergency() {

	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public Date getIncomeTime() {
		return incomeTime;
	}

	public void setIncomeTime(Date incomeTime) {
		this.incomeTime = incomeTime;
	}

	public Date getResolveTime() {
		return resolveTime;
	}

	public void setResolveTime(Date resolveTime) {
		this.resolveTime = resolveTime;
	}

	public User getSender() {
		return sender;
	}

	public void setSender(User sender) {
		this.sender = sender;
	}

	public User getResolver() {
		return resolver;
	}

	public void setResolver(User resolver) {
		this.resolver = resolver;
	}

	public String getResolveDurationString() {
		if (resolveTime != null) {
			long totalTime = (resolveTime.getTime() - incomeTime.getTime()) / 1000;
			long hours = totalTime / 3600;
			long minutes = (totalTime % 3600) / 60;
			long seconds = totalTime % 60;
			
			return String.format("%02d:%02d:%02d", hours, minutes, seconds);
		}
		return "";
	}

}
