package instituicao;
import pessoa.Aluno;
import pessoa.Professor;

public class Turma{

	private static int ultimaTurma;
	private int codigoTurma;
	private String diciplina;
	private int qtdAluno = 0;
	private Professor professor;
	protected Aluno alunos[] = new Aluno[30];
	private int aprovado;
	private float porcentagem;
	
	public Turma() {
		codigoTurma = ++ultimaTurma;
	}
	
	public Turma(String diciplina) {
		codigoTurma = ++ultimaTurma;
		setDiciplina(diciplina);
	}
	
	public Turma(String diciplina, Professor professor) {
		codigoTurma = ++ultimaTurma;
		setDiciplina(diciplina);
		setProfessor(professor);
	}
	
	public Turma(String diciplina, Professor professor, int qtd) {
		codigoTurma = ++ultimaTurma;
		setDiciplina(diciplina);
		setProfessor(professor);
		setQtdAluno(qtd);
	}
	
	public String getDiciplina() {
		return diciplina;
	}
	
	public void setDiciplina(String diciplina) {
		this.diciplina = diciplina;
	}
	
	public int getCodigoTurma() {
		return codigoTurma;
	}
	
	public void setProfessor(Professor professor) {
		this.professor = professor;
	}
	
	public Professor getProfessor() {
		return professor;
	}
	
	public int getQtdAluno() {
		return qtdAluno;
	}
	
	public void setQtdAluno(int qtd) {
		this.qtdAluno = qtd;
	}
	
	public static int getUltimaTurma() {
		return ultimaTurma;
	}
	
	public int aprovado() {
		for (int i=0; i<qtdAluno; i++) {
			if(alunos[i].media(alunos[i].getNotas()) >= 7) {
				aprovado++;
			}
		}
		return aprovado;
	}
	public int getAprovado() {
		return aprovado;
	}
	public void zeraAprovado() {
		aprovado = 0;
	}
	
	public float porcentagem(int aprovado) {
		porcentagem = (aprovado * 100)/qtdAluno;
		return porcentagem;
	}
	public float getPorcentagem() {
		return porcentagem;
	}
	public void zeraPorcentagem() {
		porcentagem = 0;
	}
}