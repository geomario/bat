#include "BATApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
BATApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

BATApp::BATApp(InputParameters parameters) : MooseApp(parameters)
{
  BATApp::registerAll(_factory, _action_factory, _syntax);
}

BATApp::~BATApp() {}

void
BATApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"BATApp"});
  Registry::registerActionsTo(af, {"BATApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
BATApp::registerApps()
{
  registerApp(BATApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
BATApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  BATApp::registerAll(f, af, s);
}
extern "C" void
BATApp__registerApps()
{
  BATApp::registerApps();
}
