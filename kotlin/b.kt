import java.util.Scanner;

fun main(){
 val reader = Scanner(System.`in`);
 var t : Int = reader.nextInt();
 while(t > 0){
 var n : Int = reader.nextInt();
 if( n < 3 ){
  println("0");
 }else{
  if( n % 2 == 0){
   println( (n/2)-1);  
  }else{
   println( n/2);
  }
 }
 t--;
 }
}