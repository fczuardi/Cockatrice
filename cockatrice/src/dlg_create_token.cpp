#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include "dlg_create_token.h"

DlgCreateToken::DlgCreateToken(QWidget *parent)
	: QDialog(parent)
{
	nameLabel = new QLabel(tr("&Name:"));
	nameEdit = new QLineEdit(tr("Token"));
	nameEdit->selectAll();
	nameLabel->setBuddy(nameEdit);

	colorLabel = new QLabel(tr("C&olor:"));
	colorEdit = new QComboBox;
	colorEdit->addItem(tr("white"), "w");
	colorEdit->addItem(tr("blue"), "u");
	colorEdit->addItem(tr("black"), "b");
	colorEdit->addItem(tr("red"), "r");
	colorEdit->addItem(tr("green"), "g");
	colorEdit->addItem(tr("multicolor"), "m");
	colorEdit->addItem(tr("colorless"), "");
	colorLabel->setBuddy(colorEdit);

	ptLabel = new QLabel(tr("&P/T:"));
	ptEdit = new QLineEdit;
	ptLabel->setBuddy(ptEdit);

	annotationLabel = new QLabel(tr("&Annotation:"));
	annotationEdit = new QLineEdit;
	annotationLabel->setBuddy(annotationEdit);
	
	destroyCheckBox = new QCheckBox(tr("&Destroy token when it leaves the table"));
	destroyCheckBox->setChecked(true);

	QGridLayout *grid = new QGridLayout;
	grid->addWidget(nameLabel, 0, 0);
	grid->addWidget(nameEdit, 0, 1);
	grid->addWidget(colorLabel, 1, 0);
	grid->addWidget(colorEdit, 1, 1);
	grid->addWidget(ptLabel, 2, 0);
	grid->addWidget(ptEdit, 2, 1);
	grid->addWidget(annotationLabel, 3, 0);
	grid->addWidget(annotationEdit, 3, 1);
	grid->addWidget(destroyCheckBox, 4, 0, 1, 2);
	
	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	connect(buttonBox, SIGNAL(accepted()), this, SLOT(actOk()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
	
	QVBoxLayout *mainLayout = new QVBoxLayout;
	mainLayout->addLayout(grid);
	mainLayout->addWidget(buttonBox);
	setLayout(mainLayout);

	setWindowTitle(tr("Create token"));
	setFixedHeight(sizeHint().height());
	setMinimumWidth(300);
}

void DlgCreateToken::actOk()
{
	accept();
}

QString DlgCreateToken::getName() const
{
	return nameEdit->text();
}

QString DlgCreateToken::getColor() const
{
	return colorEdit->itemData(colorEdit->currentIndex()).toString();
}

QString DlgCreateToken::getPT() const
{
	return ptEdit->text();
}

QString DlgCreateToken::getAnnotation() const
{
	return annotationEdit->text();
}

bool DlgCreateToken::getDestroy() const
{
	return destroyCheckBox->isChecked();
}
