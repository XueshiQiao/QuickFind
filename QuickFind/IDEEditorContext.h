//
//  IDEEditorContext.h
//  QuickFind
//
//  Created by Joey on 11/29/14.
//  Copyright (c) 2014 www.joeyio.com. All rights reserved.
//


#import <Cocoa/Cocoa.h>

@interface DVTTextDocumentLocation : NSObject
@property (readonly) NSRange characterRange;
@property (readonly) NSRange lineRange;
@end

@interface DVTTextPreferences : NSObject
+ (id)preferences;
@property BOOL trimWhitespaceOnlyLines;
@property BOOL trimTrailingWhitespace;
@property BOOL useSyntaxAwareIndenting;
@end

@interface DVTSourceTextStorage : NSTextStorage
- (void)replaceCharactersInRange:(NSRange)range withString:(NSString *)string withUndoManager:(id)undoManager;
- (NSRange)lineRangeForCharacterRange:(NSRange)range;
- (NSRange)characterRangeForLineRange:(NSRange)range;
- (void)indentCharacterRange:(NSRange)range undoManager:(id)undoManager;
@end

@interface DVTFileDataType : NSObject
@property (readonly) NSString *identifier;
@end

@interface DVTFilePath : NSObject
@property (readonly) NSURL *fileURL;
@property (readonly) DVTFileDataType *fileDataTypePresumed;
@end

@interface IDEContainerItem : NSObject
@property (readonly) DVTFilePath *resolvedFilePath;
@end

@interface IDEGroup : IDEContainerItem

@end

@interface IDEFileReference : IDEContainerItem

@end

@interface IDENavigableItem : NSObject
@property (readonly) IDENavigableItem *parentItem;
@property (readonly) id representedObject;
@end

@interface IDEFileNavigableItem : IDENavigableItem
@property (readonly) DVTFileDataType *documentType;
@property (readonly) NSURL *fileURL;
@end

@interface IDEStructureNavigator : NSObject
@property (retain) NSArray *selectedObjects;
@end

@interface IDENavigableItemCoordinator : NSObject
- (id)structureNavigableItemForDocumentURL:(id)arg1 inWorkspace:(id)arg2 error:(id *)arg3;
@end

@interface IDENavigatorArea : NSObject
- (id)currentNavigator;
@end

@interface IDEWorkspaceTabController : NSObject
@property (readonly) IDENavigatorArea *navigatorArea;
@end

@interface IDEDocumentController : NSDocumentController
+ (id)editorDocumentForNavigableItem:(id)arg1;
+ (id)retainedEditorDocumentForNavigableItem:(id)arg1 error:(id *)arg2;
+ (void)releaseEditorDocument:(id)arg1;
@end

@interface IDESourceCodeDocument : NSDocument
- (DVTSourceTextStorage *)textStorage;
- (NSUndoManager *)undoManager;
- (id)findStringMatchingDescriptor:(id)arg1 backwards:(BOOL)arg2 from:(id)arg3 to:(id)arg4;
@end

@interface IDESourceCodeComparisonEditor : NSObject
@property (readonly) NSTextView *keyTextView;
@property (retain) NSDocument *primaryDocument;
@end

@interface IDESourceCodeEditor : NSObject
@property (retain) NSTextView *textView;
- (IDESourceCodeDocument *)sourceCodeDocument;

- (struct _NSRange)selectedRangeForFindBar:(id)arg1;
- (id)startingLocationForFindBar:(id)arg1 findingBackwards:(BOOL)arg2;
- (void)dvtFindBar:(id)arg1 didUpdateCurrentResult:(id)arg2;
- (void)dvtFindBar:(id)arg1 didUpdateResults:(id)arg2;

@end

@interface DVTFindBar : NSObject
{
    NSPopUpButton *_finderModePopUpButton;
    NSSegmentedControl *_segmentedControl;
    NSTextField *_replaceTextField;
    NSTimer *_editedTimer;
    NSMutableArray *_recents;
    id _findObject;
    double _preferredViewHeight;
    NSAttributedString *_findAttributedString;
    NSAttributedString *_replaceAttributedString;
    unsigned long long _finderMode;
    BOOL _canReplace;
    BOOL _hasResults;
    BOOL _recentsNeedUpdate;
    long long _numberOfMatches;
    NSView *_findBarView;
    NSSegmentedControl *_replaceSegmentedControl;
    NSSegmentedControl *_doneSegmentedButtom;
}

+ (id)keyPathsForValuesAffectingReplaceString;
+ (id)keyPathsForValuesAffectingFindRegularExpression;
+ (id)keyPathsForValuesAffectingFindString;
+ (void)initialize;
@property __weak NSSegmentedControl *doneSegmentedButtom; // @synthesize doneSegmentedButtom=_doneSegmentedButtom;
@property __weak NSSegmentedControl *replaceSegmentedControl; // @synthesize replaceSegmentedControl=_replaceSegmentedControl;
@property __weak NSView *findBarView; // @synthesize findBarView=_findBarView;
@property(nonatomic) long long numberOfMatches; // @synthesize numberOfMatches=_numberOfMatches;
@property BOOL recentsNeedUpdate; // @synthesize recentsNeedUpdate=_recentsNeedUpdate;
@property double preferredViewHeight; // @synthesize preferredViewHeight=_preferredViewHeight;
@property(nonatomic) BOOL hasResults; // @synthesize hasResults=_hasResults;
@property BOOL canReplace; // @synthesize canReplace=_canReplace;
@property(nonatomic) unsigned long long finderMode; // @synthesize finderMode=_finderMode;
@property(copy, nonatomic) NSAttributedString *replaceAttributedString; // @synthesize replaceAttributedString=_replaceAttributedString;
@property(copy, nonatomic) NSAttributedString *findAttributedString; // @synthesize findAttributedString=_findAttributedString;
@property(retain, nonatomic) id findObject; // @synthesize findObject=_findObject;
- (void)primitiveInvalidate;
- (BOOL)control:(id)arg1 textView:(id)arg2 doCommandBySelector:(SEL)arg3;
- (void)didPressDismissOnScopeBar:(id)arg1;
- (void)controlTextDidEndEditing:(id)arg1;
- (void)_endedEditing:(id)arg1;
- (void)findBarLostFocus;
- (void)controlTextDidChange:(id)arg1;
- (void)findPatternField:(id)arg1 findPatternDoubleClicked:(id)arg2;
- (BOOL)hasFindPattern;
- (id)replaceFieldForField:(id)arg1;
- (id)findFieldForField:(id)arg1;
- (id)_replaceField;
- (id)_findField;
- (BOOL)supportsPatterns;
- (id)_recentsMenu;
- (void)_showFindOptionsPopover:(id)arg1;
- (void)_clearRecents;
- (void)_restoreFindHistory:(id)arg1;
- (void)_replaceSegmentedControlClicked:(id)arg1;
- (void)_dismiss:(id)arg1;
- (void)_replaceAllInSelectionButtonAction:(id)arg1;
- (void)_segmentedControlAction:(id)arg1;
- (void)_replaceStringFieldAction:(id)arg1;
- (void)_findStringFieldAction:(id)arg1;
- (void)cancel:(id)arg1;
- (void)_insertFindPattern:(id)arg1;
- (void)_optionsChanged:(id)arg1;
- (BOOL)supportsCaseInsensitiveMatch;
- (BOOL)supportsTextMatchStyle:(int)arg1;
- (BOOL)supportsFindBarMode:(unsigned long long)arg1;
- (BOOL)supportsFindBarType:(unsigned long long)arg1;
- (void)performFindHighlightingFirstResult:(BOOL)arg1 informDelegate:(BOOL)arg2;
- (void)clearResults;
- (void)updateStatusInformingDelegate:(BOOL)arg1;
- (void)invalidateResults;
- (void)invalidateResultsAndUpdate:(BOOL)arg1;
- (double)invalidationDelayInterval;
- (void)_updateAfterInvalidate:(id)arg1;
- (void)changeFinderMode:(id)arg1;
- (void)replaceAllInSelection:(id)arg1;
- (void)replaceAll:(id)arg1;
- (void)replaceAndFindPrevious:(id)arg1;
- (void)replaceAndFindNext:(id)arg1;
- (void)replace:(id)arg1;
@property(readonly) BOOL supportsReplace;
- (void)findPrevious:(id)arg1;
- (void)findNext:(id)arg1;
@property(readonly) BOOL replaceFieldHasFocus;
- (void)selectReplaceField:(id)arg1;
@property(readonly) BOOL findFieldHasFocus;
- (void)selectFindField:(id)arg1;
@property(readonly) BOOL viewIsInstalled;
//@property(readonly) DVTFindBarOptionsCtrl *optionsCtrl;
//@property(readonly) DVTLogAspect *logAspect;
@property BOOL ignoreNextInvalidate;
@property BOOL findResultsValid;
- (BOOL)shouldCloseOnEscape;
- (void)wasAssociatedWithScopeBarController:(id)arg1;
@property(readonly, nonatomic) NSString *replaceExpression;
@property(copy) NSString *replaceString;
@property(readonly, nonatomic) NSString *findRegularExpression;
@property(copy, nonatomic) NSString *findString;
- (void)setFindAttributedStringAndUpdate:(id)arg1;
- (void)setFindAttributedString:(id)arg1 andUpdate:(BOOL)arg2;
- (void)updateRecentsMenu;
- (void)sanitizeStrings;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)_updateSharedFindStateReplaceAttributedString:(id)arg1;
- (void)_updateSharedFindStateFindAttributedString:(id)arg1;
- (void)windowDidUpdate:(id)arg1;
- (void)viewWillUninstall;
- (void)viewDidInstall;
- (void)loadView;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;

@end


@interface IDEEditorContext : NSObject {
    DVTFindBar *_findBar;
}

@property(retain, nonatomic) id editor; // returns the current editor(IDEEditor). If the editor is the code editor, the class is `IDESourceCodeEditor`

- (void)replaceAndFindPrevious:(id)arg1;
- (void)replaceAndFindNext:(id)arg1;
- (void)replaceAll:(id)arg1;
- (void)replace:(id)arg1;
- (void)findPrevious:(id)arg1;
- (void)findNext:(id)arg1;
- (void)findAndReplace:(id)arg1;
- (void)find:(id)arg1;
- (id)_findScopeBar;
- (id)_findBar;
- (void)_installFindBar;
@end


@interface IDEDebugArea : NSObject

+ (id)createShowRightViewButton;
+ (id)createShowLeftViewButton;
- (void)activateConsole;
- (BOOL)canActivateConsole;
- (void)clearConsole;
- (BOOL)canClearConsole;
@property(readonly) NSString *stateSavingIdentifier;
@end

@interface IDEConsoleArea : NSObject

- (void)findPrevious:(id)arg1;
- (void)findNext:(id)arg1;
- (void)find:(id)arg1;

- (id)_findBar:(BOOL)arg1;
- (id)_createFindBar;
- (void)_installFindBar;
- (BOOL)_isFindBarInstalled;

@end

@interface IDEDefaultDebugArea : NSObject

@property(readonly) IDEConsoleArea *consoleArea;

@end


//@interface IDEConsoleTextView  : NSObject
//
//@end

//@interface DVTSourceTextView : NSObject
//
//@end


@interface IDEEditorArea : NSObject
- (IDEEditorContext *)lastActiveEditorContext;

@property(retain) IDEDebugArea *activeDebuggerArea; // @synthesize activeDebuggerArea=_activeDebuggerArea;
//@property(retain) IDEDebugBar *activeDebuggerBar; // @synthesize activeDebuggerBar=_activeDebuggerBar;

@property(nonatomic) int versionEditorSubmode; // @synthesize versionEditorSubmode=_versionEditorSubmode;
@property(nonatomic) int editorMode; // @synthesize editorMode=_editorMode

@end

@interface IDEWorkspaceWindowController : NSObject
@property (readonly) IDEWorkspaceTabController *activeWorkspaceTabController;
@property(readonly, getter=isInMiniDebuggingMode) BOOL inMiniDebuggingMode; // @synthesize inMiniDebuggingMode=_inMiniDebuggingMode;

- (IDEEditorArea *)editorArea;


@end

@interface IDEWorkspace : NSObject
@property (readonly) DVTFilePath *representingFilePath;
@end

@interface IDEWorkspaceDocument : NSDocument
@property (readonly) IDEWorkspace *workspace;
@end

@interface DVTFindDescriptor : NSObject <NSCopying, NSCoding>
{
}

+ (id)keyPathsForValuesAffectingDisplayAttributedString;
- (id)firstMatchingResultInString:(id)arg1 backwards:(BOOL)arg2 inRange:(struct _NSRange)arg3 withWordFindingBlock:(id)arg4 docLocationCreationBlock:(void)arg5;
- (id)firstMatchingResultInString:(id)arg1 backwards:(BOOL)arg2 inRange:(struct _NSRange)arg3 docLocationCreationBlock:(id)arg4;
@property(readonly) BOOL caseSensitive;
@property(readonly) NSString *displayString;
@property(readonly) NSAttributedString *displayAttributedString;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;

@end

@interface DVTFindTextualDescriptor : DVTFindDescriptor
{
    NSString *_findString;
    int _matchStyle;
    BOOL _caseSensitive;
}

@property(readonly) int matchStyle; // @synthesize matchStyle=_matchStyle;
- (BOOL)caseSensitive;
@property(readonly) NSString *findString; // @synthesize findString=_findString;
- (id)firstMatchingResultInString:(id)arg1 backwards:(BOOL)arg2 inRange:(struct _NSRange)arg3 withWordFindingBlock:(id)arg4 docLocationCreationBlock:(void)arg5;
- (struct _NSRange)_wordBoundaryAtIndex:(unsigned long long)arg1 forString:(id)arg2;
- (id)description;
- (id)displayString;
- (BOOL)isEqual:(id)arg1;
- (unsigned long long)hash;
- (id)initWithString:(id)arg1 ignoreCase:(BOOL)arg2 matchStyle:(int)arg3;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;

@end



