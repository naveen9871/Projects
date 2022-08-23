import * as React from 'react';
import {Button, View, Text, SafeAreaView} from 'react-native';

const ExploreScreen = ({navigation}) => {
  return (
    <SafeAreaView style={{flex: 1}}>
      <View style={{flex: 1, padding: 16}}>
        <View
          style={{
            flex: 1,
            alignItems: 'center',
            justifyContent: 'center',
          }}>
          <Text
            style={{
              fontSize: 25,
              textAlign: 'center',
              marginBottom: 16,
            }}>
            COMMITEE MEMBERS
          </Text>
          <Button
            onPress={() => navigation.navigate('SettingScreen')}
            title="NP_SOLUTIONS CEO"
          />
          <Button
            onPress={() => navigation.navigate('HelloScreen')}
            title="NP_SOLUTIONS ASSISTANT MEMBER"
          />
        </View>
        <Text
          style={{
            fontSize: 18,
            textAlign: 'center',
            color: 'grey'
          }}>
          
        </Text>
        <Text
          style={{
            fontSize: 16,
            textAlign: 'center',
            color: 'grey'
          }}>
          
        </Text>
      </View>
    </SafeAreaView>
  );
};

export default ExploreScreen;