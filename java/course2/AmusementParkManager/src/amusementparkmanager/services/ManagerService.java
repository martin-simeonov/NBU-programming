/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.services;

import amusementparkmanager.entities.Manager;
import java.util.List;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import org.hibernate.HibernateException;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;

/**
 *
 * @author Marto
 */
public class ManagerService {

    private static SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

    public static ObservableList<Manager> getManagers() {
        Session session = sessionFactory.openSession();
        Transaction tx = null;

        try {
            tx = session.beginTransaction();
            List managers = session.createQuery("FROM Manager").list();
            ObservableList<Manager> managersList = FXCollections.observableArrayList(managers);
            tx.commit();
            return managersList;
        } catch (HibernateException e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        } finally {
            session.close();
        }
        return null;
    }
    
    public static ObservableList<Manager> getAvailableManagers() {
        ObservableList<Manager> managers = getManagers();
        if (managers != null) {
            managers.removeIf(m -> !m.getParks().isEmpty());
        }
        return managers;
    }
    
    public static int addManager(String name, double salary) {
        Session session = sessionFactory.openSession();
        Transaction tx = null;
        Integer managerId = null;

        try {
            tx = session.beginTransaction();
            Manager manager = new Manager(name, salary, 0);
            managerId = (Integer) session.save(manager);
            tx.commit();
        } catch (HibernateException e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        } finally {
            session.close();
        }
        return managerId;
    }
    
    /* Method to UPDATE manager */
    public static void update(Manager manager) {
        Session session = sessionFactory.openSession();
        Transaction tx = null;

        try {
            tx = session.beginTransaction();
            session.update(manager);
            tx.commit();
        } catch (HibernateException e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        } finally {
            session.close();
        }
    }
    
}
