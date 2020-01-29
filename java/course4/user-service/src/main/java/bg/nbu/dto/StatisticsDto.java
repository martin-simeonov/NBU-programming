package bg.nbu.dto;

import java.util.HashMap;
import java.util.Map;

public class StatisticsDto {
    private Map<String, Long> countBySkill;
    private Map<String, Long> countByMake;
    private Map<Long, Long> countByYear;

    public StatisticsDto() {
        countBySkill = new HashMap<>();
        countByMake = new HashMap<>();
        countByYear = new HashMap<>();
    }

    public Map<String, Long> getCountBySkill() {
        return countBySkill;
    }

    public void setCountBySkill(Map<String, Long> countBySkill) {
        this.countBySkill = countBySkill;
    }

    public Map<String, Long> getCountByMake() {
        return countByMake;
    }

    public void setCountByMake(Map<String, Long> countByMake) {
        this.countByMake = countByMake;
    }

    public Map<Long, Long> getCountByYear() {
        return countByYear;
    }

    public void setCountByYear(Map<Long, Long> countByYear) {
        this.countByYear = countByYear;
    }
}
