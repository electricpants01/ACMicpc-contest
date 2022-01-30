import java.util.*;

public class microwave {
    public static void main(String [] args) {
        Scanner in = new Scanner(System.in);
        String [] timer = in.next().split(":");
        int minute = Integer.parseInt(timer[0]);
        int second = Integer.parseInt(timer[1]);

        int intendedTimeInSecond = (minute * 60) + second;
        int unintendedTimeInSecond = (minute * 3600) + (second * 60);
        int extraTime = unintendedTimeInSecond - intendedTimeInSecond;

        int extraHour = extraTime / 3600;
        extraTime = extraTime % 3600;
        int extraMinute = extraTime / 60;
        int extraSecond = extraTime % 60;
        
        System.out.println( String.format("%02d", extraHour) + ":" + 
                            String.format("%02d", extraMinute) + ":" +
                            String.format("%02d", extraSecond));

    }
}