package pessoa;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

import filme.Filme;
import principal.Programa;

public class Pessoa implements Serializable {

	private static final long serialVersionUID = 1L;
	private String nome;
	private String paisOrigem;
	private Pessoa conjuge;
	private List<Filme> filmes;

	public Pessoa() {

	}

	public Pessoa(String nome, String paisOrigem) {
		this.nome = nome;
		this.paisOrigem = paisOrigem;
		this.filmes = new ArrayList<>();
	}

	public Pessoa(String nome, String paisOrigem, Pessoa conjuge) {
		this.nome = nome;
		this.paisOrigem = paisOrigem;
		this.conjuge = conjuge;
		this.filmes = new ArrayList<>();
	}
	
	public void listFilmes() {
		for(Filme filme : filmes) {
			System.out.println("Filme: " + filme.getNome());
		}
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getPaisOrigem() {
		return paisOrigem;
	}

	public void setPaisOrigem(String paisOrigem) {
		this.paisOrigem = paisOrigem;
	}

	public Pessoa getConjuge() {
		return conjuge;
	}

	public void setConjuge(Pessoa conjuge) {
		this.conjuge = conjuge;
	}
	
	public void addFilme(Filme filme) {
		this.filmes.add(filme);
		Programa.setDataChanged();
	}

	public void removeFilme(Filme filme) {
		this.filmes.remove(filme);
		Programa.setDataChanged();
	}
	
	public boolean equals(Object obj) {
		if(this == obj) {
			return true;
		}
		if(obj == null || getClass() != obj.getClass()) {
			return false;
		}
		Pessoa pessoa = (Pessoa) obj;
		return Objects.equals(nome, pessoa.nome) && Objects.equals(paisOrigem, pessoa.paisOrigem);
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(nome, paisOrigem);
	}
}