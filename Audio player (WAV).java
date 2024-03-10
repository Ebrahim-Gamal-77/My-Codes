package learning;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;
import javax.sound.sampled.*;

public class Main {
    public static void main(String[] args) throws UnsupportedAudioFileException, IOException, LineUnavailableException {

        try(Scanner scanner = new Scanner(System.in)) {
            File file = new File("G:\\سورة الانسان الشيخ حسن صالح.wav");
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(file);
            Clip clip = AudioSystem.getClip();
            clip.open(audioStream);

            String response = "";
            while (!response.equals("Q")) {

                System.out.println("P = Play , S = Stop , R = Reset , Quit = Q");
                System.out.print("Enter your choice: ");
                response = scanner.next().toUpperCase();

                switch (response) {
                    case "P":
                        clip.start();
                        System.out.println("The sound is playing\n");
                        break;
                    case "S":
                        clip.stop();
                        System.out.println("The sound stopped\n");
                        break;
                    case "R":
                        clip.setMicrosecondPosition(0);
                        System.out.println("The sound reset\n");
                        break;
                    case "Q":
                        clip.close();
                        System.out.println("Bye");
                        break;
                    default:
                        System.out.println("Not a valid response\n");
                }

            }

        }

    }

}
