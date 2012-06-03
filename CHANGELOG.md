2012-06-01 wooster v0.4.0
-------------------------
Major changes:

The metrics module has been integrated into `ApptentiveConnect` proper. Now that you can enable and disable metrics from the website, it didn't make sense to keep them separate.

Bug fixes:
* IOS-40: On debug builds, the configuration is updated much more often to aid debugging. See df7aa47dce369e6caad8c18ff72b8f9cb0485050.
* IOS-41: Added metrics for surveys and for feedback submission. See e4ce211834737c08b8a5fe9591dffc14b884304f.
* IOS-38: Fixed bug where the paperclip blocked feedback text when there was no email field and no thumbnail. See f0d7c6e52ee8053653d5ae346ddebb626f9b048e.
* IOS-31: Now sending time to completion of surveys with the response. See 40b1e1e221a0fe60826da2b5ff31877485c72451.


2012-03-26 wooster v0.3.3
-------------------------

Fixes problem wherein app wouldn't use the correct ratings configuration from the server.

2012-03-25 wooster
------------------
Major changes:

* Start of version 0.3.
* Ratings flow configuration is now done server-side. Old parameters in SDK no longer exist.
* There are now server-side on/off switches for both ratings and metrics.
* Added initial version of surveys.
* Ratings parameter counters (days of use, significant events) can be reset on version upgrade.
* Including armv6 (non-thumb) architecture in all libraries.
* "Distribution" target in FeedbackDemo builds a static library distribution.
* Application exit events wired up in Metrics module.
* Adding `initialName` property to ATConnect for pre-populating the user's name.

##### Metrics
The metrics module can be used by simply linking against the `libApptentiveMetrics.a` static library. That's it. You can turn metrics on or off server side in your app settings.

##### Surveys
This is a very rough initial version of surveys. To use, link against `libApptentiveSurveys.a`.

Specific bug fixes and features:

* IOS-3: App Exit events don't seem to be sent?
* IOS-6: $ARCHS_STANDARD_32_BIT is now armv7 only, needs to be changed to armv6 and armv7
* IOS-11: Surveys Module on iOS
* IOS-21: Support for Server Side Ratings Settings
* IOS-22: Option to clear ratings parameter values (days of use, events, etc.) on version upgrade
* IOS-34: Add support for prepopulating the user's name

2012-01-13 wooster
------------------
* Start of version 0.2.
* Added support for adding and removing extra data to feedback.
* Added initial version of metrics module.
* Added support for optionally showing or hiding the email address field on feedback.
* Added support for setting an initial email address on the feedback form.

To add data to feedback, use these methods on `ATConnect`:

``` objective-c
- (void)addAdditionalInfoToFeedback:(NSObject<NSCoding> *)object withKey:(NSString *)key;
- (void)removeAdditionalInfoFromFeedbackWithKey:(NSString *)key;
```

The data objects should, at this time, either be of type `NSString` or `NSDate`. They will be added to the `record[data]` hash, with the key as the key, as in `record[data][key]`.

If you add the metrics module to your project, it will load on run. It's experimental at this point, so I wouldn't recommend using it quite yet.

You can use these properties to control email field behavior on the feedback form:

``` objective-c
@property (nonatomic, assign) BOOL showEmailField;
@property (nonatomic, retain) NSString *initialEmailAddress;
```

`showEmailField` controls whether or not the email address field is shown on the feedback form. `initialEmailAddress` can be used to set the initial email address that populates the field. Note: if the user submits feedback with a different email address, `initialEmailAddress` will not be used.