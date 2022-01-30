import java.util.Scanner

fun main(){
 var reader = Scanner(System.`in`)
 println("introduce el tipo de temperatura que se tiene (Celcius, Farenheit o Kelvin) Ex. C, F, K)");
 var origin = reader.nextLine().single()
 println("introduce el tipo de temperatura que se quiere obtener (Celcius, Farenheit o Kelvin) Ex. C, F, K)");
 var destino = reader.nextLine().single()
 println("introduce la temperatura")
 var temperature = reader.nextDouble()
 var answer = -1.0
 println("-------------------Loading------------------------")
 if(origin == 'C'){
	println("entro a Celcius :D")
	when(destino){
		'F' -> answer = (temperature * 9/5) + 32
		'K' -> answer = temperature + 273.15
	}
 }else if(origin == 'F'){
	 when(destino){
			'C' -> answer = (temperature - 32) * 5/9
			'K' -> answer = (temperature - 32) * 5/9 + 273.15
		}
 }else if(origin == 'K'){
	when(destino){
			'C' -> answer = temperature - 273.15
			'F' -> answer = (temperature - 273.15) * 9/5 + 32 
		}
 }
 
 if( answer == -1.0){
	wrongType()
 }else{
	println("el dato ${temperature}${origin} convertido es: ${answer}${destino}")
 }
	
}

fun wrongType(){
 println("El tipo de temperatura no esta en el formato correcto, Celcius -> C  Kelvin -> K  Farenheit -> F")
}