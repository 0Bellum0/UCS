package filme;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Objects;

import pessoa.Ator;
import pessoa.Diretor;
import principal.Programa;
import principal.Tela;

public class Filme implements Serializable {
	private static final long serialVersionUID = 1L;
	private String nome;
	private int ano;
	private int duracao;
	private String descricao;
	private Diretor diretor;
	private List<Ator> atores;
	private List<String> generos;
	private static String generoSelecionado;
	
	public Filme() {
		this.atores = new ArrayList<>();
		this.generos = new ArrayList<>();
	}

	public Filme(String nome, int ano, int duracao, String descricao) {
		this.nome = nome;
		this.ano = ano;
		this.duracao = duracao;
		this.descricao = descricao;
		this.atores = new ArrayList<>();
		this.generos = new ArrayList<>();
	}
	
	public void addAtor(Ator ator) {
		atores.add(ator);
	}
	public void removeAtor(Ator ator) {
		atores.remove(ator);
	}
	
	public void addGenero(String genero) {
		generos.add(genero);
	}
	public void removeGenero(String genero) {
		generos.remove(genero);
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
		Programa.setDataChanged();
	}

	public int getAno() {
		return ano;
	}

	public void setAno(int ano) {
		this.ano = ano;
		Programa.setDataChanged();
	}

	public int getDuracao() {
		return duracao;
	}

	public void setDuracao(int duracao) {
		this.duracao = duracao;
		Programa.setDataChanged();
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
		Programa.setDataChanged();
	}

	public Diretor getDiretor() {
		return diretor;
	}

	public void setDiretor(Diretor diretor) {
		this.diretor = diretor;
		Programa.setDataChanged();
	}
	
	public Ator atoresIterator() {
		Iterator<Ator> itA = atores.iterator();
		Ator atorSelecionado = null;
		while (itA.hasNext()) {
			Ator atorAtual = itA.next();
			System.out.println("Ator: " + atorAtual.getNome());
			System.out.println("Deseja selecionar este ator?");
			System.out.println("Digite 1 - Sim | 0 - Não");
			boolean bo = (Tela.sc.nextInt() == 1);
			Tela.sc.nextLine();
			if (bo) {
				atorSelecionado = atorAtual;
				break;
			}
		}
		return atorSelecionado;
	}
	
	public void temAtor(Ator ator) {
		if(this.atores.contains(ator)) {
			System.out.println("Ator ja cadastrado, deseja remove-lo?");
			System.out.println("1 - Sim | 0 - Não");
			if(Tela.sc.nextInt() == 1) {
				removeAtor(ator);
			}
		}
		else {
			addAtor(ator);
			
		}
	}
	
	public void temDiretor(Diretor diretor) {
		if(this.diretor != null && this.diretor.equals(diretor)) {
			System.out.println("diretor ja cadastrado, deseja remove-lo?");
			System.out.println("1 - Sim | 0 - Não");
			if(Tela.sc.nextInt() == 1) {
				setDiretor(null);
			}
		}
		else {
			setDiretor(diretor);
		}
	}
	
	public void temGenero() {
		Genero.listaGeneros();
		System.out.println("Deseja cadastrar mais de um genero?");
		System.out.println("0 - Somente um | 1 - Mais de um");
		if(Tela.sc.nextInt() == 1) {
			System.out.println("Quantos generos?");
			int qtd = Tela.sc.nextInt();
			Tela.sc.nextLine();
			for(int i=0; i < qtd; i++) {
				System.out.println("Digite o código do genero!");
				int j = Tela.sc.nextInt() - 1;
				Tela.sc.nextLine();
				if(this.generos.isEmpty()) {
					addGenero(Genero.generos.get(j));
					continue;
				}
				if(this.generos.contains(Genero.generos.get(j))) {
					System.out.println("Genero ja cadastrado!");
					continue;
				}
				else {
					addGenero(Genero.generos.get(j));
				}
			}
		}
	
	}
	
	public String generosIterator() {
		Iterator<String> itG = generos.iterator();
		String generoAtual = null;
		while (itG.hasNext()) {
			generoAtual = itG.next();
			System.out.println(generoAtual);
			System.out.println("Deseja selecionar este genero?");
			System.out.println("Digite 1 - Sim | 0 - Não");
			boolean bo = (Tela.sc.nextInt() == 1);
			Tela.sc.nextLine();
			if (bo) {
				generoSelecionado = generoAtual;
				break;
			}
		}
		return generoSelecionado;
	}

	@Override
	public boolean equals(Object obj) {
		if(this == obj) {
			return true;
		}
		if(obj == null || getClass() != obj.getClass()) {
			return false;
		}
		Filme filme = (Filme) obj;
		return Objects.equals(nome, filme.nome) && Objects.equals(ano, filme.ano) && Objects.equals(duracao, filme.duracao);
	}
	
	@Override
	public int hashCode() {
		return Objects.hash(nome, ano, duracao);
	}
}