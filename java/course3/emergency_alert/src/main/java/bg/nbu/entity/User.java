package bg.nbu.entity;

import java.util.Collection;
import java.util.List;

import javax.persistence.*;

@Entity
@Table(uniqueConstraints = @UniqueConstraint(columnNames = "email"))
public class User {

	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	private Long id;

	private String firstName;
	private String lastName;
	private String email;
	private String password;

	public static final String RoleUser = "ROLE_USER";
	public static final String RoleAdmin = "ROLE_ADMIN";
	public static final String RoleEmployee = "ROLE_EMPLOYEE";

	@ManyToMany(fetch = FetchType.EAGER, cascade = CascadeType.ALL)
	@JoinTable(name = "users_roles", joinColumns = @JoinColumn(name = "user_id", referencedColumnName = "id"), inverseJoinColumns = @JoinColumn(name = "role_id", referencedColumnName = "id"))
	private Collection<Role> roles;

	@OneToMany(fetch = FetchType.LAZY)
	@JoinColumn(name = "sender_id")
	private List<Emergency> sentEmergencies;
	
	@OneToMany(fetch = FetchType.LAZY)
	@JoinColumn(name = "resolver_id")
	private List<Emergency> resolvedEmergencies;

	public User() {
	}

	public User(String firstName, String lastName, String email, String password) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.email = email;
		this.password = password;
	}

	public User(String firstName, String lastName, String email, String password, Collection<Role> roles) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.email = email;
		this.password = password;
		this.roles = roles;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public Collection<Role> getRoles() {
		return roles;
	}

	public void setRoles(Collection<Role> roles) {
		this.roles = roles;
	}

	@Override
	public String toString() {
		return "User{" + "id=" + id + ", firstName='" + firstName + '\'' + ", lastName='" + lastName + '\''
				+ ", email='" + email + '\'' + ", password='" + "*********" + '\'' + ", roles=" + roles + '}';
	}

	public List<Emergency> getSentEmergencies() {
		return sentEmergencies;
	}

	public void setSentEmergencies(List<Emergency> emergencies) {
		this.sentEmergencies = emergencies;
	}

	public List<Emergency> getResolvedEmergencies() {
		return resolvedEmergencies;
	}

	public void setResolvedEmergencies(List<Emergency> resolvedEmergencies) {
		this.resolvedEmergencies = resolvedEmergencies;
	}
}
