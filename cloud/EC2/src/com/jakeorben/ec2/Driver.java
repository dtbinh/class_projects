package com.jakeorben.ec2.java;

import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.auth.BasicAWSCredentials;
import com.amazonaws.regions.Region;
import com.amazonaws.regions.Regions;
import com.amazonaws.services.ec2.AmazonEC2Client;
import com.amazonaws.services.ec2.model.*;
import com.amazonaws.services.simpleemail.AmazonSimpleEmailService;
import com.amazonaws.services.simpleemail.AmazonSimpleEmailServiceClient;
import com.amazonaws.services.simpleemail.model.*;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Driver {
    static String ACCESSKEY = "";
    static String SECRETKEY = "";
    static final String FROM = "orbenj1@tcnj.edu";
    static final String TO = "orbenjc@gmail.com";
    static final String BODY = "This email was sent through Amazon SES by using the AWS SDK for Java.";
    static final String SUBJECT = "Amazon SES test (AWS SDK for Java)";

    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        System.out.println("ListEmail: ");
        listEmail();
        System.out.println("sends email: ");
        System.out.println("please press enter to continue");
        scan.nextLine();
        sendEmail();
        System.out.println("launches intsance: ");
        System.out.println("please press enter to continue");
        scan.nextLine();
        launchInstance();
        System.out.println("describes instance: ");
        System.out.println("please press enter to continue");
        scan.nextLine();
        describe();
        System.out.println("terminates instance: ");
        System.out.println("please press enter to continue");
        scan.nextLine();
        killInstance();
    }
    public static void listEmail(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonSimpleEmailService ses = new AmazonSimpleEmailServiceClient(credentials);
        ListVerifiedEmailAddressesResult verifiedEmails = ses.listVerifiedEmailAddresses();
        System.out.println(verifiedEmails);
    }
    public static void sendEmail(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonSimpleEmailService ses = new AmazonSimpleEmailServiceClient(credentials);
        System.out.println(ses.getSendQuota());
        System.out.println(ses.getSendStatistics());
        // Construct an object to contain the recipient address.
        Destination destination = new Destination().withToAddresses(new String[]{TO});

        String verify;
        String deverify;
        String cc0;
        String cc1;
        String bcc0;
        String bcc1;

        Scanner scan = new Scanner(System.in);

        System.out.println("Address to verify: ");
        verify = scan.next();
        System.out.println("Address to cc: ");
        cc0 = scan.next();
        System.out.println("Second address to cc: ");
        cc1 = scan.next();
        System.out.println("Address to bcc: ");
        bcc0 = scan.next();
        System.out.println("Second address to bcc: ");
        bcc1 = scan.next();

        List<String> cc = new ArrayList<String>();
        cc.add(cc0);
        cc.add(cc1);
        List<String> bcc = new ArrayList<String>();
        bcc.add(bcc0);
        bcc.add(bcc1);
        destination.setCcAddresses(cc);
        destination.setBccAddresses(bcc);

        ses.verifyEmailAddress(new VerifyEmailAddressRequest().withEmailAddress(verify));

        System.out.println("Enter address to deverify: ");
        deverify = scan.next();

        ses.deleteVerifiedEmailAddress(new DeleteVerifiedEmailAddressRequest().withEmailAddress(deverify));

        // Create the subject and body of the message.
        Content subject = new Content().withData(SUBJECT);
        Content textBody = new Content().withData(BODY);
        Body body = new Body().withText(textBody);

        // Create a message with the specified subject and body.
        Message message = new Message().withSubject(subject).withBody(body);
        // Assemble the email.
        SendEmailRequest request = new SendEmailRequest().withSource(FROM).withDestination(destination).withMessage(message);

        Region REGION = Region.getRegion(Regions.US_EAST_1);
        ses.setRegion(REGION);

        // Send the email.
        ses.sendEmail(request);
        System.out.println("Email sent!");
    }

    public static void launchInstance(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonEC2Client ec2 = new AmazonEC2Client(credentials);
        RunInstancesRequest runInstancesRequest = new RunInstancesRequest()
                .withInstanceType("t2.micro")
                .withImageId("ami-b27830da")
                .withMinCount(1)
                .withMaxCount(1)
                .withKeyName("ec2_test")
                ;
        ec2.runInstances(runInstancesRequest);
        String ID;
        Scanner scan = new Scanner(System.in);
        System.out.println("Please enter the instance ID to retrieve IP: ");
        ID = scan.nextLine();
        DescribeInstancesRequest request = new DescribeInstancesRequest().withInstanceIds(ID);
        DescribeInstancesResult result = ec2.describeInstances(request);
        List <Reservation> list  = result.getReservations();

        for (Reservation res:list) {
            List <Instance> instanceList= res.getInstances();

            for (Instance instance:instanceList){

                System.out.println("Instance Public IP :" + instance.getPublicIpAddress());

            }
        }
        System.out.println("Instance launched!");

    }

    public static void describe(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonEC2Client ec2 = new AmazonEC2Client(credentials);
        DescribeInstancesResult result = ec2.describeInstances();

        System.out.println(result.toString());

        List<Reservation> reservations = result.getReservations();

        System.out.println("List of instances:");

        for (Reservation reservation : reservations) {
            List<Instance> instances = reservation.getInstances();

            for (Instance instance : instances) {
                System.out.println(instance.getInstanceId());
            }
        }
    }

    public static void killInstance(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonEC2Client ec2 = new AmazonEC2Client(credentials);
        String ID;
        Scanner scan = new Scanner(System.in);
        System.out.println("Please enter the instance ID to terminate: ");
        ID = scan.nextLine();
        TerminateInstancesRequest terminateInstancesRequest = new TerminateInstancesRequest().withInstanceIds(ID);
        ec2.terminateInstances(terminateInstancesRequest);
    }

}