package pessoa;

public class Aluno extends Pessoa {

	private int curso;
	private float notas [] = new float[3];
	private float media;
	private int codigoAluno;
	private static int ultimoAluno = 0;
	
	public Aluno() {
		
	}

	public Aluno(String nome, String cpf, String email, int idade) {
		super(nome, cpf, email, idade);
		codigoAluno = ++ultimoAluno;
	}
	
	public Aluno(String nome, String cpf, String email, int idade, int curso, float notas[]) {
		super(nome, cpf, email, idade);
		codigoAluno = ++ultimoAluno;
		setCurso(curso);
		setNotas(notas);
	}

	public int getCurso() {
		return curso;
	}

	public void setCurso(int curso) {
		this.curso = curso;
	}

	public float[] getNotas() {
		return notas;
	}

	public void setNotas(float notas[]) {
		this.notas = notas;
	}
	
	public float media(float notas[]) {
		media = 0;
		for(int i=0; i<3; i++) {
			media += notas[i];
		}
		media /= 3;
		return media;
	}
	
	public int getCodigoAluno() {
		return codigoAluno;
	}
	
	public static int getUltimoAluno() {
		return ultimoAluno;
	}
}