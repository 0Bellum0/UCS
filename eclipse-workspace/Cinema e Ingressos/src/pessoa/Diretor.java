package pessoa;

public class Diretor extends Pessoa {

	private static final long serialVersionUID = 1L;

	public Diretor() {
		super();
	}

	public Diretor(String nome, String paisOrigem) {
		super(nome, paisOrigem);
	}

	public Diretor(String nome, String paisOrigem, Pessoa conjuge) {
		super(nome, paisOrigem, conjuge);
	}
}