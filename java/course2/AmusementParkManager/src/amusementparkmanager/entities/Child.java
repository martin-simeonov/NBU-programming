package amusementparkmanager.entities;
// Generated Jan 16, 2019 3:49:40 PM by Hibernate Tools 4.3.1

/**
 * Child generated by hbm2java
 */
public class Child implements java.io.Serializable {

    private Integer childId;
    private String name;
    private Integer age;

    public Child() {
    }

    public Child(String name, Integer age) {
        this.name = name;
        this.age = age;
    }

    public Integer getChildId() {
        return this.childId;
    }

    public void setChildId(Integer childId) {
        this.childId = childId;
    }

    public Integer getAge() {
        return this.age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    @Override
    public String toString() {
        return name + " age: " + age;
    }

}
