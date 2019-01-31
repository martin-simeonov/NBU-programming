/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package amusementparkmanager.services;

import amusementparkmanager.entities.Installation;
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
public class InstallationService {
    
    private static SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

    /* Method to CREATE a installation in the database */
    public static Integer addInstallation(String name, int minAge) {
        Session session = sessionFactory.openSession();
        Transaction tx = null;
        Integer installationId = null;

        try {
            tx = session.beginTransaction();
            Installation installation = new Installation(name, minAge);
            installationId = (Integer) session.save(installation);
            tx.commit();
        } catch (HibernateException e) {
            if (tx != null) {
                tx.rollback();
            }
            e.printStackTrace();
        } finally {
            session.close();
        }
        return installationId;
    }
    
    /* Return installatino by given ID */
    public static Installation getInstallation(int installationId) {
        Session session = sessionFactory.openSession();
        Transaction tx = null;

        try {
            tx = session.beginTransaction();
            Installation installation = (Installation) session.get(Installation.class, installationId);
            tx.commit();
            return installation;
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
    
    /* Method to return all installations */
    public static ObservableList<Installation> getInstallations() {
        Session session = sessionFactory.openSession();
        Transaction tx = null;

        try {
            tx = session.beginTransaction();
            List installations = session.createQuery("FROM Installation").list();
            ObservableList<Installation> installationsList = FXCollections.observableArrayList(installations);
            tx.commit();
            return installationsList;
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
    
}
