package programa;
import instituicao.InstituicaoTI;

public class Principal {

	public static void main(String[] args) {
		
		InstituicaoTI iti = new InstituicaoTI();
		
		Tela tela = new Tela();
		
		tela.console(iti);
	}
}