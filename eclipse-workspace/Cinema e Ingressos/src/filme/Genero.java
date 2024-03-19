package filme;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public abstract class Genero implements Serializable{

	private static final long serialVersionUID = 1L;
	static List<String> generos = new ArrayList<String>();

	static {
		generos.add("Ação");
		generos.add("Drama");
		generos.add("Romance");
		generos.add("Policial");
		generos.add("Suspense");
		generos.add("Guerra");
		generos.add("Documentário");
		generos.add("Terror");
		generos.add("Ficção Científica");
		generos.add("Triller");
		generos.add("Geek");
		generos.add("Anime");
		generos.add("Infantil");
	}
	public static void listaGeneros() {
		int j = 1;
		System.out.println("Generos disponíveis: ");
		for(int i=0; i<generos.size(); i++) {
			System.out.println(j + " - " + generos.get(i));
			j++;
		}
	}
}