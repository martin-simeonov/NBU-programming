package bg.nbu.dto;

import javax.validation.constraints.Email;
import javax.validation.constraints.NotBlank;

public class ShopRegistrationDto {

	@NotBlank(message = "Provide First Name")
    private String firstName;

	@NotBlank(message = "Provide Password")
    private String password;

	@NotBlank(message = "Confirm Password")
    private String confirmPassword;

    @Email
    private String email;

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getConfirmPassword() {
        return confirmPassword;
    }

    public void setConfirmPassword(String confirmPassword) {
        this.confirmPassword = confirmPassword;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }
    
}
