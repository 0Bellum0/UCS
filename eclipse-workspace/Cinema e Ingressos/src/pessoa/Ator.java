package pessoa;

public class Ator extends Pessoa {

	private static final long serialVersionUID = 1L;

	public Ator() {
		super();
	}

	public Ator(String nome, String paisOrigem) {
		super(nome, paisOrigem);
	}

	public Ator(String nome, String paisOrigem, Pessoa conjuge) {
		super(nome, paisOrigem, conjuge);
	}
}