package estabelecimento;

import java.io.Serializable;

public class Assento implements Serializable{
	private static final long serialVersionUID = 1L;
	private char fileira;
	private int numero;
	private boolean ocupado;

	public Assento() {

	}

	public Assento(char fileira, int numero) {
		this.fileira = fileira;
		this.numero = numero;
		this.ocupado = false;
	}

	public boolean getOcupado() {
		return this.ocupado;
	}

	public void setOcupado(boolean ocupado) {
		this.ocupado = ocupado;
	}

	public char getFileira() {
		return fileira;
	}

	public void setFileira(char fileira) {
		this.fileira = fileira;
	}

	public int getNumero() {
		return numero;
	}

	public void setNumero(int numero) {
		this.numero = numero;
	}
}