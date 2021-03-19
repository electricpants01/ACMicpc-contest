import java.util.Scanner;
import java.lang.Math;

fun main(){
 val reader = Scanner(System.`in`);
 var t = reader.nextInt();
// val numbers : MutableList<Int> = mutableListOf();
 while( t > 0){
 var n : Int = reader.nextInt();
 var sum : Double = 0.0;
  for(i in 0..(n-1)){
   var a : Int = reader.nextInt();
   sum += a;
  }
 println( Math.ceil(sum / n).toInt());
 t--;
 }
}