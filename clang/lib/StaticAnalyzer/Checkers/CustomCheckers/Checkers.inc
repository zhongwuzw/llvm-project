#ifdef GET_CHECKERS

CHECKER("alpha.core.MainCallChecker", CustomMainCallChecker, "Checks for calls to main", "", true)
CHECKER("alpha.core.ObjcUIViewControllerInitializeOverrideChecker", ObjcUIViewControllerInitializeOverrideChecker, "Checks override UIViewController's initialize", "", true)


#endif // GET_CHECKERS
