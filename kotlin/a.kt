import java.util.Scanner


fun main(){
 val reader = Scanner(System.`in`)
 var t : Int = reader.nextInt();
 while(t > 0 ){
 var a : Int = reader.nextInt();
 var b : Int = reader.nextInt();
 println(a+b);
 t--;
 }  
}