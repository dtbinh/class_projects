package com.jakeorben.s3;

import java.io.*;
import java.io.File;
import java.io.FileWriter;
import java.util.*;

import com.amazonaws.AmazonClientException;
import com.amazonaws.AmazonServiceException;
import com.amazonaws.auth.AWSCredentials;
import com.amazonaws.auth.BasicAWSCredentials;
import com.amazonaws.services.s3.model.*;
import com.amazonaws.util.StringUtils;
import com.amazonaws.services.s3.AmazonS3;
import com.amazonaws.services.s3.AmazonS3Client;
import com.amazonaws.services.s3.model.ObjectMetadata;

public class Driver{
    static String ACCESSKEY = "";
    static String SECRETKEY = "";

    public static void main(String[] args) throws IOException {
        Scanner scan = new Scanner(System.in);
        System.out.println("List buckets.");
		listAll();
        System.out.println("Uploads a file.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        upload();
        System.out.println("Gets file.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        get();
        System.out.println("Deletes file.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        delete();
        System.out.println("Creates a bucket.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        createBucket();
        System.out.println("List buckets.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        listAll();
        System.out.println("Tests if object exists.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        exists();
        System.out.println("Uploads a file.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        upload();
        System.out.println("Copies file between buckets.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        copy();
        System.out.println("Deletes files.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        delete();
        System.out.println("Deletes a bucket.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        deleteBucket();
        System.out.println("Sets expiration date on a file.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        expires();
        System.out.println("Enabels versioning in a bucket.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        versioning();
        System.out.println("Uploads a file.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        upload();
        System.out.println("Uploads a file.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        upload();
        System.out.println("Lists versions and deletes one.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        uploadVersion();
        System.out.println("Gets object's metadata.");
        System.out.println("Please press enter to continue.");
        scan.nextLine();
        getMeta();
	}
    public static void listAll(){

        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);

        List<Bucket> buckets = conn.listBuckets();
        for (Bucket bucket : buckets) {
            System.out.println(bucket.getName() + "\t" +
                    StringUtils.fromDate(bucket.getCreationDate()));
        }
    }
    public static void upload() {
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        try {
            System.out.println("Uploading a new object to S3 from a file\n");

            File file = new File("test.txt");

            try {
                FileWriter out = new FileWriter(file);
                out.write("Depasta");
                out.close();
            } catch (IOException e) {
                System.out.println("Dicks.");
            }

            conn.putObject(new PutObjectRequest(
                    "tcnj-csc470-orbenj1", "test.txt", file).withStorageClass("REDUCED_REDUNDANCY"));

        } catch (AmazonServiceException ase) {
            System.out.println("Caught an AmazonServiceException, which " +
                    "means your request made it " +
                    "to Amazon S3, but was rejected with an error response" +
                    " for some reason.");
            System.out.println("Error Message:    " + ase.getMessage());
            System.out.println("HTTP Status Code: " + ase.getStatusCode());
            System.out.println("AWS Error Code:   " + ase.getErrorCode());
            System.out.println("Error Type:       " + ase.getErrorType());
            System.out.println("Request ID:       " + ase.getRequestId());
        } catch (AmazonClientException ace) {
            System.out.println("Caught an AmazonClientException, which " +
                    "means the client encountered " +
                    "an internal error while trying to " +
                    "communicate with S3, " +
                    "such as not being able to access the network.");
            System.out.println("Error Message: " + ace.getMessage());
        }
    }
    public static void get() throws IOException {
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        try {
            System.out.println("Downloading an object");
            S3Object s3object = conn.getObject(new GetObjectRequest(
                    "tcnj-csc470-orbenj1", "test.txt"));
            System.out.println("Content-Type: "  +
                    s3object.getObjectMetadata().getContentType());
            displayTextInputStream(s3object.getObjectContent());

            // Get a range of bytes from an object.

            GetObjectRequest rangeObjectRequest = new GetObjectRequest(
                    "tcnj-csc470-orbenj1", "test.txt");
            rangeObjectRequest.setRange(0, 10);
            S3Object objectPortion = conn.getObject(rangeObjectRequest);

            System.out.println("Printing bytes retrieved.");
            displayTextInputStream(objectPortion.getObjectContent());

        } catch (AmazonServiceException ase) {
            System.out.println("Caught an AmazonServiceException, which" +
                    " means your request made it " +
                    "to Amazon S3, but was rejected with an error response" +
                    " for some reason.");
            System.out.println("Error Message:    " + ase.getMessage());
            System.out.println("HTTP Status Code: " + ase.getStatusCode());
            System.out.println("AWS Error Code:   " + ase.getErrorCode());
            System.out.println("Error Type:       " + ase.getErrorType());
            System.out.println("Request ID:       " + ase.getRequestId());
        } catch (AmazonClientException ace) {
            System.out.println("Caught an AmazonClientException, which means"+
                    " the client encountered " +
                    "an internal error while trying to " +
                    "communicate with S3, " +
                    "such as not being able to access the network.");
            System.out.println("Error Message: " + ace.getMessage());
        }
    }

    public static void displayTextInputStream(InputStream input)
            throws IOException {
        // Read one text line at a time and display.
        BufferedReader reader = new BufferedReader(new
                InputStreamReader(input));
        while (true) {
            String line = reader.readLine();
            if (line == null) break;

            System.out.println("    " + line);
        }
        System.out.println();
    }

    public static void delete(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        try {
            conn.deleteObject(new DeleteObjectRequest("tcnj-csc470-orbenj1", "test.txt"));
            System.out.println("File successfully deleted.");
        } catch (AmazonServiceException ase) {
            System.out.println("Caught an AmazonServiceException.");
            System.out.println("Error Message:    " + ase.getMessage());
            System.out.println("HTTP Status Code: " + ase.getStatusCode());
            System.out.println("AWS Error Code:   " + ase.getErrorCode());
            System.out.println("Error Type:       " + ase.getErrorType());
            System.out.println("Request ID:       " + ase.getRequestId());
        } catch (AmazonClientException ace) {
            System.out.println("Caught an AmazonClientException.");
            System.out.println("Error Message: " + ace.getMessage());
        }
    }

    public static void createBucket(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        Bucket bucket = conn.createBucket("arousingbucket1992");
        System.out.println("A new bucket has been successfully created.");
    }

    public static void exists(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        System.out.println("Bucket exists: " + conn.doesBucketExist("arousingbucket1992"));
    }

    public static void deleteBucket(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        conn.deleteBucket("arousingbucket1992");
        System.out.println("Bucket successfully deleted.");
    }

    public static void copy(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        conn.copyObject("tcnj-csc470-orbenj1", "test.txt", "arousingbucket1992", "test.txt");
        System.out.println("Copy successful.");
        try {
            conn.deleteObject(new DeleteObjectRequest("arousingbucket1992", "test.txt"));
            System.out.println("File successfully deleted.");
        } catch (AmazonServiceException ase) {
            System.out.println("Caught an AmazonServiceException.");
            System.out.println("Error Message:    " + ase.getMessage());
            System.out.println("HTTP Status Code: " + ase.getStatusCode());
            System.out.println("AWS Error Code:   " + ase.getErrorCode());
            System.out.println("Error Type:       " + ase.getErrorType());
            System.out.println("Request ID:       " + ase.getRequestId());
        } catch (AmazonClientException ace) {
            System.out.println("Caught an AmazonClientException.");
            System.out.println("Error Message: " + ace.getMessage());
        }

    }

    public static void expires(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        try {
            System.out.println("Uploading a new object to S3 from a file\n");
            File file = new File("test.txt");

            try {
                FileWriter out = new FileWriter(file);
                out.write("Depasta");
                out.close();
            } catch (IOException e) {
                System.out.println("Dicks.");
            }
            BucketLifecycleConfiguration config = new BucketLifecycleConfiguration();
            BucketLifecycleConfiguration.Rule expire = new BucketLifecycleConfiguration.Rule().withId("test.txt").withExpirationInDays(5).withStatus(BucketLifecycleConfiguration.ENABLED.toString());
            config.withRules(expire);
            conn.setBucketLifecycleConfiguration("tcnj-csc470-orbenj1", config);

            System.out.println("Your file will expire.");

        } catch (AmazonServiceException ase) {
            System.out.println("Caught an AmazonServiceException, which " +
                    "means your request made it " +
                    "to Amazon S3, but was rejected with an error response" +
                    " for some reason.");
            System.out.println("Error Message:    " + ase.getMessage());
            System.out.println("HTTP Status Code: " + ase.getStatusCode());
            System.out.println("AWS Error Code:   " + ase.getErrorCode());
            System.out.println("Error Type:       " + ase.getErrorType());
            System.out.println("Request ID:       " + ase.getRequestId());
        } catch (AmazonClientException ace) {
            System.out.println("Caught an AmazonClientException, which " +
                    "means the client encountered " +
                    "an internal error while trying to " +
                    "communicate with S3, " +
                    "such as not being able to access the network.");
            System.out.println("Error Message: " + ace.getMessage());
        }

    }

    public static void versioning(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        SetBucketVersioningConfigurationRequest request =
                new SetBucketVersioningConfigurationRequest("tcnj-csc470-orbenj1",
                        new BucketVersioningConfiguration(BucketVersioningConfiguration.ENABLED));
        conn.setBucketVersioningConfiguration(request);
        System.out.println("Versioning enabeled.");
    }


    public static void uploadVersion() {
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        ListIterator verListIt = conn.listVersions("tcnj-csc470-orbenj1", "test.txt").getVersionSummaries().listIterator();
        String versionID = "";
        while (verListIt.hasNext()) {
            S3VersionSummary current = (S3VersionSummary)verListIt.next();
            System.out.println(current.getVersionId());
            versionID = current.getVersionId();
        }
        conn.deleteVersion("tcnj-csc470-orbenj1", "test.txt", versionID);
        System.out.println("File successfully deleted.");
    }
    public static void getMeta(){
        AWSCredentials credentials = new BasicAWSCredentials(ACCESSKEY, SECRETKEY);
        AmazonS3 conn = new AmazonS3Client(credentials);
        GetObjectMetadataRequest request = new GetObjectMetadataRequest("tcnj-csc470-orbenj1", "test.txt");
        System.out.println(conn.getObjectMetadata(request).getContentType());
    }
}