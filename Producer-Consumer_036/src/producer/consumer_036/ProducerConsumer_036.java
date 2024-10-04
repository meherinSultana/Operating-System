package producer.consumer_036;

/**
 *
 * @author User Unknown
 */
public class ProducerConsumer_036 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here

        Share buffer = new Share();
        producer producer1 = new producer(buffer, "Producer 1");
        consumer consumer1 = new consumer(buffer, "Consumer 1");
        producer producer2 = new producer(buffer, "Producer 2");
        consumer consumer2 = new consumer(buffer, "Consumer 2");

        producer1.start();
        producer2.start();
        consumer1.start();
        consumer2.start();
    }

}
