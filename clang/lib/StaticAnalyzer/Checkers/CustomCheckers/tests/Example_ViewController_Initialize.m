// RUN: %clang -cc1 -analyze -load libCustomCheckers.dylib  -analyzer-checker=alpha.core  /Users/zhongwu/Documents/workspace/Example_ViewController_Initialize.m %s

// Define used Classes
@protocol NSObject
- (id)retain;
- (oneway void)release;
@end
@interface NSObject <NSObject> {}
- (id)init;
+ (id)alloc;
@end
@interface NSCoder : NSObject {}
@end

// Define the Superclasses for our Checks
@interface UIViewController : NSObject {}
@end

@interface UIViewController (Category)
@end

@implementation UIViewController (Category)
+ (void)initialize {}
@end

