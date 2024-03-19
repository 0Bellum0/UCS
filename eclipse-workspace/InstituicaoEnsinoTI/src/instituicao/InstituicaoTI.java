package instituicao;
import java.util.Arrays;
import pessoa.Aluno;
import pessoa.Professor;
import programa.Tela;

public class InstituicaoTI {

	private static final String cursos[] = {"1 - Ciência de Computação", "2 - Engenharia de Software",
											"3 - Engenharia de Computação", "4 - Análise e Desenvolvimento de Sistemas"};
	private Turma turmas[] = new Turma[100];
	private int tindex = 0;
	private Professor professores[] = new Professor[100];
	private int pindex = 0;
	private int cod = 0;
	private int percent;
	//private float notas[] = new float[3];
	//private int codTurma;
	
	public InstituicaoTI() {
		
	}
	
	public String[] getCursos() {
		return InstituicaoTI.cursos;
	}
	
	private String qualCurso(int curso) {
		return cursos[curso];
	}
	
	public Turma[] getTurmas() {
		return turmas;
	}
	
	public int getPercent() {
		return percent;
	}
	public void setPercent() {
		percent = (percent * 100)/Aluno.getUltimoAluno();
	}
	public void zeraPercent() {
		percent = 0;
	}
	
	public void listarTurmas() {
		for(int i=0; i<tindex; i++) {
			System.out.println("Turma: " + turmas[i].getCodigoTurma());
			System.out.println("Diciplina: " + turmas[i].getDiciplina());
			System.out.println("Professor: " + turmas[i].getProfessor().getCodProfessor() + " - " + turmas[i].getProfessor().getNome());
			System.out.println("Qtd Alunos: " + turmas[i].getQtdAluno());
			
		}
	}
	
	public void listarContingente() {
		for(int i=0; i<tindex; i++) {
			System.out.println("Turma: " + turmas[i].getCodigoTurma());
			System.out.println("Diciplina: " + turmas[i].getDiciplina());
			System.out.println("Professor: " + turmas[i].getProfessor().getCodProfessor() + " - " + turmas[i].getProfessor().getNome());
			System.out.println("Qtd Alunos: " + turmas[i].getQtdAluno());
			turmas[i].zeraAprovado();
			turmas[i].zeraPorcentagem();
			System.out.println("Alunos aprovados: " + turmas[i].aprovado());
			System.out.println("% Aprovados: " + turmas[i].porcentagem(turmas[i].getAprovado()) + "%");
		}
		System.out.println("Total de alunos matriculados: " + Aluno.getUltimoAluno());
		for (int j=0; j<Turma.getUltimaTurma(); j++) {
			percent += turmas[j].getAprovado();
		}
		setPercent();
		System.out.println("Porcentagem total de aprovados: " + getPercent() + "%");
		zeraPercent();
	}
	
	public void infoTurma(int i) {
		
		System.out.println("Turma: " + turmas[i].getCodigoTurma());
		System.out.println("Diciplina: " + turmas[i].getDiciplina());
		System.out.println("Professor: " + turmas[i].getProfessor().getCodProfessor() + " - " + turmas[i].getProfessor().getNome());
		for(int j=0; j<turmas[i].getQtdAluno(); j++) {
			System.out.println("Aluno: " + turmas[i].alunos[j].getNome());
			System.out.println("Curso: " + qualCurso(turmas[i].alunos[j].getCurso()));
			System.out.println("Notas: " + Arrays.toString(turmas[i].alunos[j].getNotas()));
			System.out.println("Média: " + turmas[i].alunos[j].media(turmas[i].alunos[j].getNotas()));
			if(turmas[i].alunos[j].media(turmas[i].alunos[j].getNotas()) >= 7) {
				System.out.println("Aprovado!");
			}
			else {
				System.out.println("Reprovado!");
			}
		}
	}
	
	public boolean cadProf() {
		System.out.println("Deseja cadastrar um novo professor?");
		System.out.println("1 - Sim | 0 - Não");
		//Scanner sc = new Scanner(System.in);
		//int resposta = Tela.sc.nextInt();
		boolean bool = (/*resposta*/Tela.sc.nextInt() == 1);
		Tela.sc.nextLine();
		//Tela.sc.close();
		return bool;
	}
	
	public void cadastrarTurma() {
		
		boolean bo = cadProf();
		
		if(bo == true) {
			
			String nome, cpf, email;
			int idade;
			float salario;
			
			//Scanner sc = new Scanner(System.in);
			System.out.println("Digite o nome do professor: ");
			nome = Tela.sc.nextLine();
			System.out.println("Digite o CPF: ");
			cpf = Tela.sc.nextLine();
			System.out.println("Digite o e-mail: ");
			email = Tela.sc.nextLine();
			System.out.println("Digite a idade: ");
			idade = Tela.sc.nextInt();
			Tela.sc.nextLine();
			System.out.println("Digite o Salário: ");
			salario = Tela.sc.nextFloat();
			Tela.sc.nextLine();
			//sc.close();
			
			cod = pindex;
			professores[pindex++] = new Professor(nome, cpf, email, idade, salario);
		}
		
		else if(bo == false) {
			
			System.out.println("Digite o código do professor: ");
			//Scanner sc = new Scanner(System.in);
			cod = (Tela.sc.nextInt() - 1);
			Tela.sc.nextLine();
			//sc.close();
		}

		int qtd;
		String diciplina;

		//Scanner sc = new Scanner(System.in);
		System.out.println("Digite a diciplina: ");
		diciplina = Tela.sc.nextLine();
		System.out.println("Digite a quantidade de alunos: ");
		qtd = Tela.sc.nextInt();
		Tela.sc.nextLine();
		if(qtd > 30) {
			do {
			System.out.println("Digite um valor menor do que 30!");
			qtd = Tela.sc.nextInt();
			Tela.sc.nextLine();
			}
			while(qtd > 30);
		}
		//sc.close();
		
		int codTurma = tindex;
		turmas[tindex++] = new Turma(diciplina, professores[cod], qtd);
		
		String nome, cpf, email;
		int idade, curso;

		for(int i=0; i<qtd; i++) {
			
			float notas[] = new float[3];
			
			System.out.println("Digite o nome do aluno: ");
			nome = Tela.sc.nextLine();
			System.out.println("Digite o CPF: ");
			cpf = Tela.sc.nextLine();
			System.out.println("Digite o e-mail: ");
			email = Tela.sc.nextLine();
			System.out.println("Digite a idade: ");
			idade = Tela.sc.nextInt();
			Tela.sc.nextLine();
			System.out.println("Cursos: " + Arrays.toString(getCursos()));
			System.out.println("Digite o código do curso de 1 a 4: ");
			curso = (Tela.sc.nextInt() - 1);
			Tela.sc.nextLine();
			for(int j=0; j<3; j++) {
				System.out.println("Digite a Nota " + (j+1) + ": ");
				notas[j] = Tela.sc.nextFloat();
				Tela.sc.nextLine();
			}
			turmas[codTurma].alunos[i] = new Aluno(nome, cpf, email, idade, curso, notas);
		}
		//sc.close();
	}
}