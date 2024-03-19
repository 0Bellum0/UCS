package pessoa;

public class Professor extends Pessoa {

	private float salario;
	private static int ultimoProfessor = 0;
	private int codProfessor;
	
	public Professor() {
		codProfessor = ++ultimoProfessor;
	}

	public Professor(String nome, String cpf, String email, int idade) {
		super(nome, cpf, email, idade);
		codProfessor = ++ultimoProfessor;
	}
	
	public Professor(String nome, String cpf, String email, int idade, float salario) {
		super(nome, cpf, email, idade);
		codProfessor = ++ultimoProfessor;
		setSalario(salario);
	}
	
	public void setSalario(float salario) {
		this.salario = salario;
	}
	
	public float getSalario() {
		return salario;
	}
	public int getCodProfessor() {
		return codProfessor;
	}
}