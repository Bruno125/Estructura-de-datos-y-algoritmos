#pragma once
#include "ListaDoble.h"
#include "Obstaculo.h"

namespace Snake {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	private:
		CListaDoble* serpiente;
		CObstaculo* coin;
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// panel1
			// 
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(584, 561);
			this->panel1->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(584, 561);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 int gWidth=this->panel1->Width;
				 int gHeight=this->panel1->Height;
				 serpiente=new CListaDoble(gWidth/2,gHeight/2,20);
				 coin=new CObstaculo(gWidth,gHeight);
			 }
	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 if(e->KeyCode==Keys::Left){
					 serpiente->cambiaDireccion(IZQUIERDA);
				 }
				 if(e->KeyCode==Keys::Right){
					 serpiente->cambiaDireccion(DERECHA);
				 }
				 if(e->KeyCode==Keys::Down){
					 serpiente->cambiaDireccion(ABAJO);
				 }
				 if(e->KeyCode==Keys::Up){
					 serpiente->cambiaDireccion(ARRIBA);
				 }
				 if(e->KeyValue=='A' || e->KeyValue=='a'){
					 serpiente->AgregarAlFinal();
				 }
			 }
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {

				 Graphics ^g = this->panel1->CreateGraphics();
				int gWidth = (int)g->VisibleClipBounds.Width;
				int gHeight = (int)g->VisibleClipBounds.Height;

				BufferedGraphicsContext ^espacioBuffer = BufferedGraphicsManager::Current;
				espacioBuffer->MaximumBuffer = System::Drawing::Size( gWidth + 1, gHeight + 1 );
				BufferedGraphics ^buffer = espacioBuffer->Allocate( g, Drawing::Rectangle(0, 0, gWidth, gHeight));

				buffer->Graphics->Clear(this->BackColor);

				//---- Completar aqui

				if(serpiente->colision(coin->getX(),coin->getY(),coin->getTamaño(),coin->getTamaño())){
					serpiente->AgregarAlFinal();
					coin->resetear(gWidth,gHeight);
				}

				if(serpiente->colisionPropia())
					this->Close();

				coin->mostrar(buffer->Graphics);
				serpiente->mostrarTodos(buffer->Graphics);
				serpiente->moverTodos(gWidth,gHeight);

				buffer->Render(g);
				delete g;
				delete buffer; 

			 }
	};
}

