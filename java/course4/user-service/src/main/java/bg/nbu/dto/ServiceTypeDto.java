package bg.nbu.dto;

import bg.nbu.entity.Skill;

import java.util.HashSet;
import java.util.Set;

public class ServiceTypeDto {
    private Set<Skill> skills;

    public ServiceTypeDto() {
        skills = new HashSet<>();
    }

    public Set<Skill> getSkills() {
        return skills;
    }

    public void setSkills(Set<Skill> skills) {
        this.skills = skills;
    }
}
